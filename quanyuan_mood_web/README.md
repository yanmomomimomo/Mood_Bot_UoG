1. main() Function
Purpose: Initializes and starts the WebSocket server.

Invocation: This function is the program entry point. You don't need to call it explicitly - it runs automatically when the program starts.

Execution Flow:

main() enters the backend WebSocket server's event loop.

Within this loop, it continuously calls lws_service() to handle WebSocket events.

int main(void) {
    // Set up and initialize WebSocket environment
    // Create WebSocket context
    // Start WebSocket server and enter event loop
    while (!interrupted) {
        lws_service(context, 50); // Wait for and process events
    }
}

2. callback_websockets() Function
Purpose: Handles incoming and outgoing WebSocket messages.

Invocation: Automatically called by the libwebsockets library when events occur. The callback triggers for each client message or when data needs to be sent.

Execution Flow:

When a client sends a message: LWS_CALLBACK_RECEIVE triggers

When the WebSocket becomes writable: LWS_CALLBACK_SERVER_WRITEABLE triggers

static int callback_websockets(struct lws *wsi, enum lws_callback_reasons reason,
                               void *user, void *in, size_t len) {
    switch (reason) {
        case LWS_CALLBACK_RECEIVE:  // Called when client sends message
            printf("Received message: %.*s\n", (int)len, (char *)in);
            break;

        case LWS_CALLBACK_SERVER_WRITEABLE:  // Called when WebSocket is writable
            // Simulate mood change
            // Send mood data in JSON format
            break;

        default:
            break;
    }
    return 0;
}

3. lws_service() Function
Purpose: Core WebSocket event processing mechanism that handles events (message reception, sending, connection closure, etc.) within the event loop.

Invocation: Called by main()'s event loop. Continuously polls and processes WebSocket connection events.

Execution Flow:

while (!interrupted) {
    lws_service(context, 50);  // Process WebSocket events with 50ms timeout
}
4. lws_write() Function
Purpose: Sends data to clients. Used within LWS_CALLBACK_SERVER_WRITEABLE to transmit data to frontend.

Invocation: Called inside LWS_CALLBACK_SERVER_WRITEABLE handler.

Execution Flow:
unsigned char buf[LWS_PRE + 128]; // Allocate buffer
unsigned char *p = &buf[LWS_PRE];
snprintf((char *)p, sizeof(buf) - LWS_PRE, "{\"mood\": \"%s\"}", current_mood);
lws_write(wsi, p, strlen((char *)p), LWS_WRITE_TEXT);  // Send data
5. lws_callback_on_writable_all_protocol() Function
Purpose: Notifies WebSocket server to send data to all clients matching the protocol. Used to actively push updated mood data.

Invocation: Typically called when mood changes to initiate data transmission.

Execution Flow:
lws_callback_on_writable_all_protocol(vhost, &protocols[0]);  // Notify writable
6. sigint_handler() Function
Purpose: Captures Ctrl+C signal to gracefully terminate the program. Sets interrupted flag to break the event loop.

Invocation: Automatically triggered by OS when user presses Ctrl+C.

Execution Flow:
signal(SIGINT, sigint_handler);  // Register signal handler

Function Call Hierarchy Summary
main(): Initializes WebSocket environment and enters event loop

lws_service(): Continuously called within main() to process events

callback_websockets(): Dispatched by libwebsockets for various events

lws_write(): Executed during LWS_CALLBACK_SERVER_WRITEABLE to send data

lws_callback_on_writable_all_protocol(): Triggered on mood changes to initiate pushes

sigint_handler(): Handles graceful shutdown

Frontend Setup Instructions
To configure the frontend page, you need to enter the following commands in your computer's Command Prompt:

Navigate to the project folder:

bash
cd path/to/mood-project
Install dependencies:

bash
npm install
Start the development server:

bash
npm run dev
