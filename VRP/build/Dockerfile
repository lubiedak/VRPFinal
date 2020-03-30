FROM ubuntu:bionic

RUN apt-get update && \
	apt-get install -y build-essential git cmake make autoconf libtool pkg-config

WORKDIR /usr/include/

# We pass the boost version argument as argument
ARG BOOST_VERSION
ARG BOOST_VERSION_
ENV BOOST_VERSION=1.72.0
ENV BOOST_VERSION_=1_72_0
ENV BOOST_ROOT=/usr/include/boost

RUN apt-get -qq update && apt-get install -q -y software-properties-common
RUN add-apt-repository ppa:ubuntu-toolchain-r/test -y
RUN apt-get -qq update && apt-get install -qy g++ gcc git wget

RUN wget --max-redirect 3 https://dl.bintray.com/boostorg/release/${BOOST_VERSION}/source/boost_${BOOST_VERSION_}.tar.gz
RUN mkdir -p /usr/include/boost && tar zxf boost_${BOOST_VERSION_}.tar.gz -C /usr/include/boost --strip-components=1
