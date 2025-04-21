import React from 'react';
import { StrictMode } from 'react';
import { createRoot } from 'react-dom/client';
import App from './App.jsx';
import './index.css'; // Import global styles

// Get the root DOM element where the React app will be mounted
const rootElement = document.getElementById('root');

// Throw an error if root element is not found
if (!rootElement) {
  throw new Error("Root element not found! Please ensure your HTML has a <div id='root'></div> element");
}

// Create a root and render the application in Strict Mode
createRoot(rootElement).render(
  <StrictMode>
    <App />
  </StrictMode>
);
