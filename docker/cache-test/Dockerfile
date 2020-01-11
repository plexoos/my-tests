FROM ubuntu:18.04

WORKDIR /tmp

COPY packages.ubuntu /tmp/packages

#ENV PACKAGES="$(tr '\\n' ' ' < tmp/packages)"

RUN PACKAGES=$(tr '\n' ' ' < /tmp/packages) \
 && echo "PACKAGES: $PACKAGES" \
 && apt-get update -qq \
 && apt-get -y install $PACKAGES \
 && apt-get clean \
 && rm -rf /var/lib/apt/lists/* /tmp/*
