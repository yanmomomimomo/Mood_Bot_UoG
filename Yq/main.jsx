import React from 'react';
import { StrictMode } from 'react';
import { createRoot } from 'react-dom/client';
import App from './App.jsx';
import './index.css'; // 确保引入 index.css

// 确保 HTML 里存在 id="root" 的元素
const rootElement = document.getElementById('root');

if (!rootElement) {
  throw new Error("No root element found! Make sure you have <div id='root'></div> in index.html");
}

// 渲染 React 应用
createRoot(rootElement).render(
  <StrictMode>
    <App />
  </StrictMode>
);
