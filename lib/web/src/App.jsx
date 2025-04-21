import React, { useEffect, useState } from 'react';
import './App.css';

function App() {
  // Component state
  const [currentMood, setCurrentMood] = useState('😊');
  const [temperature, setTemperature] = useState('N/A');
  const [co2Level, setCo2Level] = useState('N/A');
  const [ws, setWs] = useState(null); // WebSocket connection instance

  // Establish WebSocket connection on component mount
  useEffect(() => {
    const socket = new WebSocket('ws://192.168.31.75:3001');
    
    // WebSocket event handlers
    socket.onopen = () => {
      console.log('WebSocket connection established');
    };
    
    socket.onmessage = (event) => {
      console.log('Received data:', event.data);
      try {
        const data = JSON.parse(event.data);
        // Update state based on received data
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

    // Cleanup function to close connection on unmount
    return () => {
      socket.close();
    };
  }, []);

  /**
   * Sends a message through the WebSocket connection
   * @param {Object} message - The message to send
   */
  const sendMessage = (message) => {
    if (ws && ws.readyState === WebSocket.OPEN) {
      ws.send(JSON.stringify(message));
    } else {
      console.error('WebSocket is not connected');
    }
  };

  /**
   * Handles mood change events
   * @param {string} mood - The selected mood emoji
   */
  const handleMoodChange = (mood) => {
    console.log('Mood changed to:', mood);
    setCurrentMood(mood);
    sendMessage({ type: 'mood', data: mood });
  };

  /**
   * Sends movement commands
   * @param {string} direction - Movement direction (forward/backward/left/right)
   */
  const handleMove = (direction) => {
    console.log('Moving:', direction);
    sendMessage({ type: 'move', data: direction });
  };

  // Activates game mode
  const startGameMode = () => {
    sendMessage({ type: 'gameMode', data: true });
  };

  // Starts remote monitoring
  const startMonitoring = () => {
    sendMessage({ type: 'startMonitoring', data: true });
  };

  return (
    <div className="container">
      <h1>MoodyBot: Your Intelligent Desktop Companion</h1>
      <p>MoodyBot helps you stay energized and balanced.</p>

      {/* Mood Recognition Section */}
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

      {/* Environment Monitoring Section */}
      <section className="card">
        <h2>🌡️ Smart Environment Control</h2>
        <p>Monitors temperature & CO₂ levels.</p>
        <div>
          <p>Temperature: {temperature}°C</p>
          <p>CO₂ Level: {co2Level} ppm</p>
        </div>
        <button onClick={() => sendMessage({ type: 'checkEnvironment' })}>
          Check Environment
        </button>
      </section>

      {/* Movement Control Section */}
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

      {/* Game Mode Section */}
      <section className="card">
        <h2>🎮 Fun & Playful Interaction</h2>
        <p>Activate game mode and let MoodyBot play.</p>
        <button onClick={startGameMode}>Start Game Mode</button>
      </section>

      {/* Remote Monitoring Section */}
      <section className="card">
        <h2>📹 Remote-Controlled Home Monitoring</h2>
        <p>Use MoodyBot as a security assistant.</p>
        <button onClick={startMonitoring}>Start Monitoring</button>
      </section>

      {/* Spacer to ensure sufficient page height */}
      <div style={{ height: '500px' }}></div>
    </div>
  );
}

export default App;
