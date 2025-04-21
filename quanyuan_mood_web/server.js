const express = require('express');
const http = require('http');
const { Server } = require('socket.io');
const { exec } = require('child_process');

const app = express();
const server = http.createServer(app);
const io = new Server(server);

// When frontend clicks a button, execute the C program
io.on('connection', (socket) => {
    console.log('A user connected');

    socket.on('mood', (mood) => {
        console.log(`Mood changed to: ${mood}`);

        // Execute the C program
        exec(`./mood_logger ${mood}`, (error, stdout, stderr) => {
            if (error) {
                console.error(`Error: ${error.message}`);
                return;
            }
            console.log(stdout);
        });
    });

    socket.on('disconnect', () => {
        console.log('User disconnected');
    });
});

server.listen(3000, () => {
    console.log('Server running on http://0.0.0.0:3000');
});