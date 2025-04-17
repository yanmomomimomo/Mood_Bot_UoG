import React, { useEffect, useState } from 'react';
import './App.css';
import io from 'socket.io-client';

function App() {
  const [currentMood, setCurrentMood] = useState('😊');
  const [temperature, setTemperature] = useState('N/A');
  const [co2Level, setCo2Level] = useState('N/A');

  const socket = io('http://localhost:3000');

  // Receive mood updates from backend
  useEffect(() => {
    socket.on('moodUpdate', (mood) => {
      console.log('Received mood from backend:', mood);
      setCurrentMood(mood);
    });

    return () => {
      socket.off('moodUpdate');
    };
  }, []);

  // Movement control handler
  const handleMove = (direction) => {
    console.log('Moving:', direction);
    socket.emit('move', direction);
  };

  const startMonitoring = () => {
    socket.emit('startMonitoring', true);
  };

  // Receive environment data from backend
  useEffect(() => {
    socket.on('environment', (data) => {
      setTemperature(data.temperature);
      setCo2Level(data.co2);
    });

    return () => {
      socket.off('environment');
    };
  }, []);

  // Disconnect socket when component unmounts
  useEffect(() => {
    return () => {
      socket.disconnect();
    };
  }, []);

  return (
    <div className="container">
      <h1>MoodyBot: Your Intelligent Desktop Companion</h1>
      <p>MoodyBot helps you stay energized and balanced.</p>

      {/* Emotion recognition section */}
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

      {/* Environment monitoring section */}
      <section className="card">
        <h2>🌡️ Smart Environment Control</h2>
        <p>Monitors temperature & CO₂ levels.</p>
        <div>
          <p>Temperature: {temperature}°C</p>
          <p>CO₂ Level: {co2Level} ppm</p>
        </div>
        <button onClick={() => socket.emit('checkEnvironment')}>Check Environment</button>
      </section>

      {/* Movement control section */}
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

      {/* Remote monitoring section */}
      <section className="card">
        <h2>📹 Remote Monitoring</h2>
        <button onClick={startMonitoring}>Start Monitoring</button>
      </section>

      {/* Empty space placeholder */}
      <div style={{ height: '500px' }}></div>
    </div>
  );
}

export default App;
