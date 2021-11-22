第一次讨论时间：21.11.10

1. 功能
   - client：
     1. 随机产生等长键值对（key和value都等长）
     2. 读请求
     3. 写请求
     4. 本地缓存实现
     5. 读server
     6. 写server
   - master：
     1. 扩容缩容
     2. 读取client的请求并返回分布信息
     3. 接收来自server的状态信息
   - cache server：
     1. 状态上报
     2. LRU键值淘汰机制
2. 算法
   - 负载均衡、扩容缩容：哈希一致性
   - cache server淘汰机制：LRU
   - client中缓存的淘汰机制：生命周期

