#!/bin/bash

SERVICE_NAME=npmdev
WORKING_DIR="/home/pi/Downloads"
SERVICE_FILE="/etc/systemd/system/${SERVICE_NAME}.service"

echo "?? 正在创建 systemd 服务：$SERVICE_NAME"

# 检查是否存在目标目录
if [ ! -d "$WORKING_DIR" ]; then
    echo "目录 $WORKING_DIR 不存在，请先确认项目路径是否正确！"
    exit 1
fi

# 创建 systemd 服务文件
sudo tee "$SERVICE_FILE" > /dev/null <<EOF
[Unit]
Description=Start npm dev server on boot
After=network.target

[Service]
ExecStart=/bin/bash -c 'cd ${WORKING_DIR} && npm run dev'
WorkingDirectory=${WORKING_DIR}
User=pi
Restart=always
Environment=PATH=/usr/bin:/usr/local/bin
Environment=NODE_ENV=production

[Install]
WantedBy=multi-user.target
EOF

# 重新加载 systemd 并启用服务
echo "重新加载 systemd 并启用服务..."
sudo systemctl daemon-reexec
sudo systemctl daemon-reload
sudo systemctl enable "$SERVICE_NAME"
sudo systemctl start "$SERVICE_NAME"

# 显示服务状态
echo "服务已启动，状态如下："
sudo systemctl status "$SERVICE_NAME" --no-pager

echo -e "设置完成，服务将在每次开机时自动运行！"
