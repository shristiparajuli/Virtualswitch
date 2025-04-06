FROM python:3.9-slim

WORKDIR /app
COPY . /app

RUN pip install torch grpcio grpcio-tools

CMD ["python", "switch/main.py"]
