import React, { useEffect, useState } from 'react';
import './App.css';
import io from 'socket.io-client';

function App() {
  const [currentMood, setCurrentMood] = useState('😊');
  const [temperature, setTemperature] = useState('N/A');
  const [co2Level, setCo2Level] = useState('N/A');

  const socket = io('http://localhost:3000');

  // Receive emotion updates from the backend (newly added)
  useEffect(() => {
    socket.on('moodUpdate', (mood) => {
      console.log('Received mood from backend:', mood);
      setCurrentMood(mood);
    });

    return () => {
      socket.off('moodUpdate');
    };
  }, []);

  // All other code remains unchanged (including handleMove, environment monitoring, etc.)
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

  // Receive environment data (remain unchanged)
  useEffect(() => {
    socket.on('environment', (data) => {
      setTemperature(data.temperature);
      setCo2Level(data.co2);
    });

    return () => {
      socket.off('environment');
    };
  }, []);

  // Disconnect on component unmount (remain unchanged)
  useEffect(() => {
    return () => {
      socket.disconnect();
    };
  }, []);

  return (
    <div className="container">
      <h1>MoodyBot: Your Intelligent Desktop Companion</h1>
      <p>MoodyBot helps you stay energized and balanced.</p>

      {/* Emotion Recognition Section (the only modified part) */}
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

      {/* Environment Monitoring Section (unchanged) */}
      <section className="card">
        <h2>🌡️ Smart Environment Control</h2>
        <p>Monitors temperature & CO₂ levels.</p>
        <div>
          <p>Temperature: {temperature}°C</p>
          <p>CO₂ Level: {co2Level} ppm</p>
        </div>
        <button onClick={() => socket.emit('checkEnvironment')}>Check Environment</button>
      </section>

      {/* Movement Control Section (unchanged) */}
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

      {/* Game Mode Section (unchanged) */}
      <section className="card">
        <h2>🎮 Fun & Playful Interaction</h2>
        <p>Activate game mode and let MoodyBot play.</p>
        <button onClick={startGameMode}>Start Game Mode</button>
      </section>

      {/* Remote Monitoring Section (unchanged) */}
      <section className="card">
        <h2>📹 Remote-Controlled Home Monitoring</h2>
        <p>Use MoodyBot as a security assistant.</p>
        <button onClick={startMonitoring}>Start Monitoring</button>
      </section>

      {/* Empty Space Section (unchanged) */}
      <div style={{ height: '500px' }}></div>
    </div>
  );
}

export default App;
