import React, { useEffect, useState } from 'react';
import './App.css';
import io from 'socket.io-client';

function App() {
  const [currentMood, setCurrentMood] = useState('😊');
  const [temperature, setTemperature] = useState('N/A');
  const [co2Level, setCo2Level] = useState('N/A');

  const socket = io('http://localhost:3000');

  // 接收后端推送的情绪变化（新增）
  useEffect(() => {
    socket.on('moodUpdate', (mood) => {
      console.log('Received mood from backend:', mood);
      setCurrentMood(mood);
    });

    return () => {
      socket.off('moodUpdate');
    };
  }, []);

  // 其他所有代码保持不变（包括 handleMove、环境监测等）
  const handleMove = (direction) => {
    console.log('Moving:', direction);
    socket.emit('move', direction);
  };

  const startGameMode = () => {
    socket.emit('gameMode', true);
  };

  const startMonitoring = () => {
    socket.emit('startMonitoring', true);
  };

  // 环境数据接收（原样保留）
  useEffect(() => {
    socket.on('environment', (data) => {
      setTemperature(data.temperature);
      setCo2Level(data.co2);
    });

    return () => {
      socket.off('environment');
    };
  }, []);

  // 组件卸载断开连接（原样保留）
  useEffect(() => {
    return () => {
      socket.disconnect();
    };
  }, []);

  return (
    <div className="container">
      <h1>MoodyBot: Your Intelligent Desktop Companion</h1>
      <p>MoodyBot helps you stay energized and balanced.</p>

      {/* 情绪识别区块（唯一修改的部分） */}
      <section className="card">
        <h2>😊 Emotional Recognition & LED Display</h2>
        <p>MoodyBot detects your emotions and reacts accordingly.</p>
        <div className="status-box">
          <h3>Current Mood: {currentMood}</h3>
          <div className="mood-display">
            <div className={`mood-item ${currentMood === '😊' ? 'active' : ''}`}>
              Happy 😊
            </div>
            <div className={`mood-item ${currentMood === '😢' ? 'active' : ''}`}>
              Sad 😢
            </div>
            <div className={`mood-item ${currentMood === '😴' ? 'active' : ''}`}>
              Tired 😴
            </div>
          </div>
        </div>
      </section>

      {/* 环境监测区块（原样保留） */}
      <section className="card">
        <h2>🌡️ Smart Environment Control</h2>
        <p>Monitors temperature & CO₂ levels.</p>
        <div>
          <p>Temperature: {temperature}°C</p>
          <p>CO₂ Level: {co2Level} ppm</p>
        </div>
        <button onClick={() => socket.emit('checkEnvironment')}>Check Environment</button>
      </section>

      {/* 移动控制区块（原样保留） */}
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

      {/* 游戏模式区块（原样保留） */}
      <section className="card">
        <h2>🎮 Fun & Playful Interaction</h2>
        <p>Activate game mode and let MoodyBot play.</p>
        <button onClick={startGameMode}>Start Game Mode</button>
      </section>

      {/* 远程监控区块（原样保留） */}
      <section className="card">
        <h2>📹 Remote-Controlled Home Monitoring</h2>
        <p>Use MoodyBot as a security assistant.</p>
        <button onClick={startMonitoring}>Start Monitoring</button>
      </section>

      {/* 空白区域（原样保留） */}
      <div style={{ height: '500px' }}></div>
    </div>
  );
}

export default App;