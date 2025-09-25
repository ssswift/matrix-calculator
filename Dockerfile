FROM ubuntu:22.04 AS builder

RUN apt-get update && \
    apt-get install -y cmake g++ git && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . .

# Устанавливаем Google Test вручную внутри контейнера
RUN git clone https://github.com/google/googletest.git -b release-1.13.0 && \
    cd googletest && \
    mkdir build && cd build && \
    cmake .. && \
    make && make install

RUN rm -rf build && \
    cmake -B build && \
    cmake --build build --target matrix_calculator

FROM ubuntu:22.04
WORKDIR /app
COPY --from=builder /app/build/matrix_calculator .
CMD ["./matrix_calculator"]
