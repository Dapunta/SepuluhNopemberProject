FROM alpine:latest
RUN apk --no-cache add gcc libc-dev
WORKDIR /app
COPY chat.c .
RUN gcc chat.c -o chat
# CMD ["./chat"]
