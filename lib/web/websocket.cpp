#include <libwebsockets.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>

static int interrupted = 0;

static int callback_websockets(struct lws *wsi, enum lws_callback_reasons reason,
                               void *user, void *in, size_t len) {
    switch (reason) {
        case LWS_CALLBACK_RECEIVE:
            // 打印收到的消息
            printf("收到消息: %.*s\n", (int)len, (char *)in);
            break;
        default:
            break;
    }
    return 0;
}

static struct lws_protocols protocols[] = {
    {
        "example-protocol", // 协议名称，与客户端无需强制匹配
        callback_websockets,
        0,
        1024,
    },
    { NULL, NULL, 0, 0 } // 结束标记
};

static void sigint_handler(int sig) {
    interrupted = 1;
}

int main(void) {
    struct lws_context_creation_info info;
    memset(&info, 0, sizeof info);
    info.port = 3001;  // 与前端连接的端口保持一致
    info.protocols = protocols;
    
    // 捕获 Ctrl+C 信号以便退出
    signal(SIGINT, sigint_handler);

    struct lws_context *context = lws_create_context(&info);
    if (!context) {
        fprintf(stderr, "libwebsockets 初始化失败\n");
        return -1;
    }

    printf("WebSocket 服务器已启动，监听端口 %d...\n", info.port);
    
    // 进入事件循环
    while (!interrupted) {
        lws_service(context, 50);
    }

    lws_context_destroy(context);
    printf("服务器已关闭\n");
    return 0;
}
