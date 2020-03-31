FROM cpp-build-base:0.1.0 AS build
WORKDIR /vrp
COPY src/ ./src/
WORKDIR /vrp
COPY CMakeLists.txt ./
RUN cmake . && make
CMD ["/vrp/VRP", "--micro=true"]