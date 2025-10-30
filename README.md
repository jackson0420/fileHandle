# fileHandle
解析excel表格内容,根据输入提取列名,按固定的格式提取后逐行放入默认或指定的.txt文件内

# QXlsx库
qt外部库,解析excel文件  
## 1.在项目目录下,下载QXlsx库  
`git clone https://github.com/QtExcel/QXlsx.git`
## 2.在.pro文件中加入
`include(QXlsx/QXlsx.pri)`

# 默认数据
## 提取列名
"SPN","FMI","P-Code","DTCB","故障"
## 生成文件路径
"D:/CreatedFile.txt"
### 更改上述内容后需点击确定保存更改内容
