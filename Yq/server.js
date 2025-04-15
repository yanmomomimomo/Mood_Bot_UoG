const express = require('express');
const http = require('http');
const socketIo = require('socket.io');
const path = require('path');

// 创建 Express 应用
const app = express();
const server = http.createServer(app);
const io = socketIo(server);

// 托管前端页面
app.use(express.static(path.join(__dirname, 'public')));

// 处理 Socket.io 连接
io.on('connection', (socket) => {
  console.log('A client connected');

  // 接收情绪数据
  socket.on('mood', (mood) => {
    console.log('Received mood:', mood);
    // 根据情绪控制 LED 或其他硬件
    switch (mood) {
      case '😊':
        console.log('Setting LED to happy mode');
        break;
      case '😢':
        console.log('Setting LED to sad mode');
        break;
      case '😴':
        console.log('Setting LED to tired mode');
        break;
      default:
        console.log('Unknown mood:', mood);
    }
  });

  // 接收环境检查请求
  socket.on('checkEnvironment', () => {
    console.log('Checking environment...');
    // 模拟环境数据
    const temperature = Math.random() * 30 + 10; // 模拟温度数据
    const co2 = Math.random() * 1000 + 400; // 模拟 CO₂ 数据
    socket.emit('environment', { temperature: temperature.toFixed(2), co2: co2.toFixed(2) });
  });

  // 接收游戏模式请求
  socket.on('gameMode', (enabled) => {
    console.log('Game mode:', enabled ? 'ON' : 'OFF');
    // 控制机器人执行游戏模式动作
  });

  // 接收远程监控请求
  socket.on('startMonitoring', (enabled) => {
    console.log('Monitoring:', enabled ? 'ON' : 'OFF');
    // 启动摄像头或其他监控设备
  });

  // 处理断开连接
  socket.on('disconnect', () => {
    console.log('A client disconnected');
  });
});

// 启动服务器
const PORT = process.env.PORT || 3000;
server.listen(PORT, () => {
  console.log(`Server is running on http://localhost:${PORT}`);
});