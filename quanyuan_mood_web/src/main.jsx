import React from 'react';
import { StrictMode } from 'react';
import { createRoot } from 'react-dom/client';
import App from './App.jsx';
import './index.css'; // Make sure to import index.css

// Ensure there's an element with id="root" in the HTML
const rootElement = document.getElementById('root');

if (!rootElement) {
  throw new Error("No root element found! Make sure you have <div id='root'></div> in index.html");
}

// Render the React application
createRoot(rootElement).render(
  <StrictMode>
    <App />
  </StrictMode>
);