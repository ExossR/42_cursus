FROM python:3.9-slim

WORKDIR /app

ENV DISPLAY=:0
ENV XDG_RUNTIME_DIR=/tmp
ENV TERM=xterm

RUN apt-get update && apt-get install -y \
    vim \
    python3-tk \
    libx11-dev \
    x11-apps \
    && rm -rf /var/lib/apt/lists/*

COPY . .

RUN pip install --no-cache-dir -r requirements.txt

CMD ["tail", "-f", "/dev/null"]
