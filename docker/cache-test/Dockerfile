FROM ubuntu:18.04

WORKDIR /tmp

COPY packages.ubuntu /tmp/packages

#RUN tr '\n' ' ' < /tmp/packages | (read PACKAGES; echo "XXX $PACKAGES")

RUN apt-get update -qq && tr '\n' ' ' < /tmp/packages | (read PACKAGES; apt-get -y install $PACKAGES)

RUN echo "YYY PACKAGES: $PACKAGES"

#RUN PACKAGES=$(cat packages) \
# && echo "PACKAGES: $PACKAGES"
# && apt-get update -qq \
# && apt-get -y install $PACKAGES \
# && apt-get clean \
# && rm -rf /var/lib/apt/lists/* /tmp/*
