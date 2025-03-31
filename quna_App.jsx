import React, { useEffect, useState } from 'react';
import './App.css';

function App() {
  const [currentMood, setCurrentMood] = useState('😊');
  const [temperature, setTemperature] = useState('N/A');
  const [co2Level, setCo2Level] = useState('N/A');
  
  // Use useState to store the WebSocket instance
  const [ws, setWs] = useState(null);

  useEffect(() => {
    // Connect to the backend WebSocket server
    const socket = new WebSocket('ws://192.168.31.75:3001');
    socket.onopen = () => {
      console.log('WebSocket connection established');
    };
    socket.onmessage = (event) => {
      console.log('Received data:', event.data);
      // Assume the backend sends data in JSON format, e.g., { temperature: 25, co2: 400 }
      try {
        const data = JSON.parse(event.data);
        if (data.temperature !== undefined) {
          setTemperature(data.temperature);
        }
        if (data.co2 !== undefined) {
          setCo2Level(data.co2);
        }
      } catch (error) {
        console.error('Error parsing data:', error);
      }
    };
    socket.onclose = () => {
      console.log('WebSocket connection closed');
    };
    setWs(socket);

    return () => {
      socket.close();
    };
  }, []);

  // Encapsulate the message sending function
  const sendMessage = (message) => {
    if (ws && ws.readyState === WebSocket.OPEN) {
      ws.send(JSON.stringify(message));
    } else {
      console.error('WebSocket is not connected yet');
    }
  };

  // Handle mood changes
  const handleMoodChange = (mood) => {
    console.log('Mood changed to:', mood);
    setCurrentMood(mood);
    sendMessage({ type: 'mood', data: mood });
  };

  // Handle movement commands
  const handleMove = (direction) => {
    console.log('Moving:', direction);
    sendMessage({ type: 'move', data: direction });
  };

  // Activate game mode
  const startGameMode = () => {
    sendMessage({ type: 'gameMode', data: true });
  };

  // Start remote monitoring
  const startMonitoring = () => {
    sendMessage({ type: 'startMonitoring', data: true });
  };

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
          <button onClick={() => handleMoodChange('😊')}>Happy</button>
          <button onClick={() => handleMoodChange('😢')}>Sad</button>
          <button onClick={() => handleMoodChange('😴')}>Tired</button>
        </div>
      </section>

      {/* Environmental monitoring section */}
      <section className="card">
        <h2>🌡️ Smart Environment Control</h2>
        <p>Monitors temperature & CO₂ levels.</p>
        <div>
          <p>Temperature: {temperature}°C</p>
          <p>CO₂ Level: {co2Level} ppm</p>
        </div>
        <button onClick={() => sendMessage({ type: 'checkEnvironment' })}>Check Environment</button>
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

      {/* Game mode section */}
      <section className="card">
        <h2>🎮 Fun & Playful Interaction</h2>
        <p>Activate game mode and let MoodyBot play.</p>
        <button onClick={startGameMode}>Start Game Mode</button>
      </section>

      {/* Remote monitoring section */}
      <section className="card">
        <h2>📹 Remote-Controlled Home Monitoring</h2>
        <p>Use MoodyBot as a security assistant.</p>
        <button onClick={startMonitoring}>Start Monitoring</button>
      </section>

      {/* Add a large blank area to ensure enough page height */}
      <div style={{ height: '500px' }}></div>
    </div>
  );
}

export default App;
