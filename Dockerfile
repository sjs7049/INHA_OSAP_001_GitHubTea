###############################################################################################
#   File Name: Dockerfile                                                                     #
#   Copyright (c) 2024 GitHubTea                                                              #
#                                                                                             #
#   This software is distributed under the MIT License.                                       #
#   For more details on the MIT License, please refer to the LICENSE file in this project.    #
#   This software is provided "as is," without any warranty of any kind.                      #
#                                                                                             #
#   Author: GitHubTea                                                                         #
#   Date: 2024-11-28                                                                          #
###############################################################################################

# 채점 서버와 같은 환경
FROM ubuntu:18.04

# Google Test를 위한 dependencies 설치

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    wget \
    libgtest-dev \
    apt-transport-https \
    ca-certificates \
    gnupg \
    software-properties-common \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# 최신 CMake 설치
RUN apt-get update && apt-get install -y apt-transport-https ca-certificates gnupg && \
    wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc | apt-key add - && \
    apt-add-repository 'deb https://apt.kitware.com/ubuntu/ bionic main' && \
    apt-get update && apt-get install -y cmake && \
    apt-get clean && rm -rf /var/lib/apt/lists/*
    

# Google Test 빌드 및 설치
RUN mkdir /googletest && cd /googletest && \
    cmake /usr/src/googletest && \
    make && make install && \
    rm -rf /googletest


# 기본적으로 root 유저로 설정되기 때문에 새로운 유저 생성 및 권한 부여
RUN useradd -m dockeruser && \
    mkdir -p /app && chown dockeruser:dockeruser /app
USER dockeruser

# /app 디렉토리에서 작업
WORKDIR /app

# 프로젝트 파일 복사
COPY --chown=dockeruser:dockeruser header/ ./header
COPY --chown=dockeruser:dockeruser source/ ./source
COPY --chown=dockeruser:dockeruser test/ ./test
COPY --chown=dockeruser:dockeruser CMakeLists.txt ./

# 빌드 디렉토리 생성 후 CMake 실행
CMD cmake -S . -B build && \
    cmake --build build && \ 
    cd build && \
    ctest --output-on-failure

