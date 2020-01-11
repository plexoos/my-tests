FROM ubuntu:18.04

WORKDIR /tmp

# Install system packages
#COPY packages.ubuntu /tmp/packages
ARG PACKAGES
ENV PACKAGES=$PACKAGES

RUN echo "PACKAGES: $PACKAGES" \
 && apt-get update -qq \
 && apt-get -y install $PACKAGES \
 && apt-get clean \
 && rm -rf /var/lib/apt/lists/* /tmp/*
