FROM cpp-build-base:0.1.0 AS build
WORKDIR /src
COPY CMakeLists.txt src/VRPCore.cpp ./
RUN cmake . && make
FROM ubuntu:bionic
WORKDIR /opt/VRP
COPY --from=build /src/VRP ./
CMD ["./VRP --micro=true"]