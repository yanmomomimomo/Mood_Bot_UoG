import { defineConfig } from 'vite'
import react from '@vitejs/plugin-react'

// https://vite.dev/config/
export default defineConfig({
  plugins: [react()],
  server: {
    host: '0.0.0.0', // Mainly this host configuration
    port: 5174, // Set the server startup port
    open: true, // Whether to automatically open browser when server starts
    cors: true, // Allow cross-origin requests
    hmr: {
      overlay: false // Disable server error overlay
    }
  }
})