FROM cpp-build-base:0.1.0 AS build
WORKDIR /vrp
COPY src/ ./src/
WORKDIR /vrp
COPY CMakeLists.txt ./
RUN ls
RUN cmake . && make
#FROM ubuntu:bionic
#WORKDIR /opt/VRP
#COPY --from=build /src/VRP ./
RUN ls 
CMD ["/vrp/VRP", "--micro=true"]