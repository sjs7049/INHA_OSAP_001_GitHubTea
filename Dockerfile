# 채점 서버와 같은 환경
FROM ubuntu:18.04

# google test를 위한 dependencies들 설치
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    libgtest-dev \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# google test 빌드 및 설치
RUN mkdir /googletest && cd /googletest && \
    cmake /usr/src/googletest && \
    make && make install && \
    rm -rf /googletest

# 기본적으로는 root 유저로 설정되기 때문에 권한 새로 생성 및 부여
RUN useradd -m dockeruser && \
    mkdir -p /app && chown dockeruser:dockeruser /app
USER dockeruser

# docker container 내부의 /app directory에서 작업 진행
WORKDIR /app

# 현재 directory에 있는 모든 파일들을 /app으로 전송
COPY --chown=dockeruser:dockeruser . .
RUN rm -rf /app/build

# test 수행
CMD ["bash", "-c", "cmake -S . -B build && cmake --build build && cd build && ctest --output-on-failure"]