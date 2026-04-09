# School Project

Dự án C++ quản lý trường học, dùng MySQL (Docker) và MySQL Connector/C++ cho migration/schema.

## Yêu cầu

- **Docker Desktop** (bật daemon khi làm việc với database trong container)
- (Tuỳ chọn) **MySQL Workbench** hoặc client khác để xem/sửa dữ liệu
- (Tuỳ chọn) **GCC** + **MySQL Connector/C++** nếu biên dịch `Migrations/db.cpp` trực tiếp trên Windows — cấu hình include/lib có thể tham chiếu `.vscode/c_cpp_properties.json`

## Cấu hình môi trường

1. Sao chép file mẫu:

   ```bash
   copy .env.example .env
   ```

   (PowerShell/CMD trên Windows; trên macOS/Linux dùng `cp`.)

2. Mở `.env` và đổi `MYSQL_ROOT_PASSWORD`, `MYSQL_PASSWORD` (và các giá trị khác nếu cần).

3. **`MYSQL_HOST=127.0.0.1`** dùng khi ứng dụng hoặc Workbench chạy **trên máy host**, còn MySQL chạy trong Docker và đã map cổng (mặc định `3306`).

## Chạy MySQL bằng Docker

Từ thư mục gốc project:

```bash
docker compose -f docker.yml up -d db
```

- Dữ liệu nằm trong volume `school_mysql_data`.
- Cổng trên máy host: `MYSQL_PUBLISH_PORT` trong `.env` (mặc định `3306`).

Dừng container (giữ volume):

```bash
docker compose -f docker.yml stop db
```

## Chạy migration (tạo DB/bảng) trong container

Sau khi service `db` healthy:

```bash
docker compose -f docker.yml run --rm app
```

Image `app` build từ `Dockerfile`, biên dịch `Migrations/db.cpp` và chạy binary `migrate`. Trong Compose, `MYSQL_HOST` được đặt thành `db` (tên service), không dùng `localhost`.

## Kết nối từ MySQL Workbench

- **Host:** `127.0.0.1` (hoặc `localhost`)
- **Port:** trùng `MYSQL_PUBLISH_PORT` trong `.env`
- **User / password:** `MYSQL_USER` / `MYSQL_PASSWORD`, hoặc `root` / `MYSQL_ROOT_PASSWORD` nếu cần quyền đầy đủ

Database mặc định theo `.env`: `MYSQL_DATABASE` (ví dụ `school`).

## Cấu trúc gợi ý

| Đường dẫn | Mô tả |
|-----------|--------|
| `Migrations/db.cpp` | Kết nối MySQL, tạo database/bảng (đọc biến môi trường) |
| `docker.yml` | Compose: MySQL + service build migration |
| `Dockerfile` | Build migration trên Ubuntu + `libmysqlcppconn-dev` |
| `.env` / `.env.example` | Thông tin kết nối (không commit `.env` nếu có mật khẩu thật) |

## Lưu ý

- Để database luôn sẵn sàng, cần **Docker Desktop chạy** và **container `db` đang chạy**. Giữ Workbench mở không bắt buộc cho việc đó.
- Nếu cổng `3306` trên máy đã bị MySQL khác chiếm, tăng `MYSQL_PUBLISH_PORT` trong `.env` (ví dụ `3307`) và kết nối Workbench đúng cổng đó.
