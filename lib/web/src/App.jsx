import React, { useEffect, useState } from 'react';
import './App.css';

function App() {
  const [currentMood, setCurrentMood] = useState('😊');
  const [temperature, setTemperature] = useState('N/A');
  const [co2Level, setCo2Level] = useState('N/A');
  
  // 使用 useState 存储 WebSocket 实例
  const [ws, setWs] = useState(null);

  useEffect(() => {
    // 连接到后端 WebSocket 服务器
    const socket = new WebSocket('ws://192.168.31.75:3001');
    socket.onopen = () => {
      console.log('WebSocket 连接已建立');
    };
    socket.onmessage = (event) => {
      console.log('收到数据:', event.data);
      // 假设后端发送的数据为 JSON 格式，例如 { temperature: 25, co2: 400 }
      try {
        const data = JSON.parse(event.data);
        if (data.temperature !== undefined) {
          setTemperature(data.temperature);
        }
        if (data.co2 !== undefined) {
          setCo2Level(data.co2);
        }
      } catch (error) {
        console.error('解析数据出错:', error);
      }
    };
    socket.onclose = () => {
      console.log('WebSocket 连接已关闭');
    };
    setWs(socket);

    return () => {
      socket.close();
    };
  }, []);

  // 封装发送消息方法
  const sendMessage = (message) => {
    if (ws && ws.readyState === WebSocket.OPEN) {
      ws.send(JSON.stringify(message));
    } else {
      console.error('WebSocket 尚未连接');
    }
  };

  // 处理情绪变化
  const handleMoodChange = (mood) => {
    console.log('Mood changed to:', mood);
    setCurrentMood(mood);
    sendMessage({ type: 'mood', data: mood });
  };

  // 处理移动指令
  const handleMove = (direction) => {
    console.log('Moving:', direction);
    sendMessage({ type: 'move', data: direction });
  };

  // 启动游戏模式
  const startGameMode = () => {
    sendMessage({ type: 'gameMode', data: true });
  };

  // 启动远程监控
  const startMonitoring = () => {
    sendMessage({ type: 'startMonitoring', data: true });
  };

  return (
    <div className="container">
      <h1>MoodyBot: Your Intelligent Desktop Companion</h1>
      <p>MoodyBot helps you stay energized and balanced.</p>

      {/* 情绪识别区块 */}
      <section className="card">
        <h2>😊 Emotional Recognition & LED Display</h2>
        <p>MoodyBot detects your emotions and reacts accordingly.</p>
        <div className="status-box">
          <h3>Current Mood: {currentMood}</h3>
          <button onClick={() => handleMoodChange('😊')}>Happy</button>
          <button onClick={() => handleMoodChange('😢')}>Sad</button>
          <button onClick={() => handleMoodChange('😴')}>Tired</button>
        </div>
      </section>

      {/* 环境监测区块 */}
      <section className="card">
        <h2>🌡️ Smart Environment Control</h2>
        <p>Monitors temperature & CO₂ levels.</p>
        <div>
          <p>Temperature: {temperature}°C</p>
          <p>CO₂ Level: {co2Level} ppm</p>
        </div>
        <button onClick={() => sendMessage({ type: 'checkEnvironment' })}>Check Environment</button>
      </section>

      {/* 移动控制区块 */}
      <section className="card">
        <h2>🚗 Movement Control</h2>
        <p>Control MoodyBot's movement.</p>
        <div className="movement-controls">
          <button onClick={() => handleMove('forward')}>↑ Forward</button>
          <div>
            <button onClick={() => handleMove('left')}>← Left</button>
            <button onClick={() => handleMove('right')}>→ Right</button>
          </div>
          <button onClick={() => handleMove('backward')}>↓ Backward</button>
        </div>
      </section>

      {/* 游戏模式区块 */}
      <section className="card">
        <h2>🎮 Fun & Playful Interaction</h2>
        <p>Activate game mode and let MoodyBot play.</p>
        <button onClick={startGameMode}>Start Game Mode</button>
      </section>

      {/* 远程监控区块 */}
      <section className="card">
        <h2>📹 Remote-Controlled Home Monitoring</h2>
        <p>Use MoodyBot as a security assistant.</p>
        <button onClick={startMonitoring}>Start Monitoring</button>
      </section>

      {/* 添加一个大空白区域，确保页面有足够高度 */}
      <div style={{ height: '500px' }}></div>
    </div>
  );
}

export default App;
