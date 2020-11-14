FROM ubuntu:20.04 
ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install --no-install-recommends -y \
    gcc g++ \
    git \
    make \
    cmake \
    cppcheck \
    valgrind \
    doxygen \
    graphviz\
    libgtest-dev \
    && rm -rf /var/lib/apt/lists/*