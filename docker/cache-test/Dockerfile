FROM ubuntu:18.04

WORKDIR /tmp

# Install system packages
COPY packages.ubuntu /tmp/packages
RUN apt-get update -qq \
 && apt-get -y install $(cat packages) \
 && apt-get clean \
 && rm -rf /var/lib/apt/lists/* /tmp/*
