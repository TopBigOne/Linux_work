测试方法：

编译运行程序：gcc server.c -o server && ./server。

另开终端用 nc 连接：nc localhost 8080，输入任意字符后回车，服务端会打印消息。

```shell
nc localhost 8080
```