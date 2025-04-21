const express = require('express');
const http = require('http');
const { Server } = require('socket.io');
const { exec } = require('child_process');

const app = express();
const server = http.createServer(app);
const io = new Server(server);

// 当前端点击按钮，执行 C 语言程序
io.on('connection', (socket) => {
    console.log('A user connected');

    socket.on('mood', (mood) => {
        console.log(`Mood changed to: ${mood}`);

        // 调用 C 语言程序
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
