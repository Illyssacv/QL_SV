FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        g++ \
        libmysqlcppconn-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY Migrations/db.cpp .

# Tìm thư mục chứa mysql_driver.h (khác nhau giữa các bản distro)
RUN set -e; \
    H="$(dpkg -L libmysqlcppconn-dev | grep -E 'mysql_driver\.h$' | head -n1)"; \
    test -n "$H"; \
    JDBC_DIR="$(dirname "$H")"; \
    g++ -std=c++17 -O2 -Wall -o migrate db.cpp \
        -I/usr/include \
        -I"$JDBC_DIR" \
        -lmysqlcppconn

CMD ["./migrate"]
