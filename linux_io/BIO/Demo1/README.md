# LINUX bio
1. 阻塞式 I/O 的核心特点
   * 同步等待：调用 read()/write() 时，如果数据未就绪（如磁盘未响应、网络无数据），线程会卡住（阻塞），直到操作完成。
   * 简单直接：适合顺序执行的逻辑，代码易写易读。
2. demo
* 阻塞式读取文件