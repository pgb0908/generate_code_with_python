import pathlib
import sys
import csv

header_file_name = '/home/bont/PycharmProjects/pythonProject/generate/GatewayExceptionCode.h'
cpp_file_name = '/home/bont/PycharmProjects/pythonProject/generate/GatewayExceptionCode.cpp'

# Exception.csv 공유 파일 배열로 읽어오기
file_path = 'Exception.csv'
data_list = []
with open(file_path, 'r', newline='', encoding='utf-8') as file:
    # CSV 파일을 읽기 위한 reader 객체 생성
    reader = csv.reader(file)

    for row in reader:
        data_list.append(row)

header = """#pragma once

#include <string>
#include "ExceptionCode.h"

namespace anylink {{
class GatewayExceptionCode: public ExceptionCode {{
private:
    std::string codeName;
    std::string code;

public:
    GatewayExceptionCode(int codeNumber, const std::string& codeName);
    virtual ~GatewayExceptionCode() = default;
    std::string getCode() const override;
    std::string getCodeName() const override;

public:
{push_back}

}};
}} /* namespace anylink */
"""

# 위 header에 배열의 값 넣어주기
output = pathlib.Path(header_file_name)
push_back = '\n'.join(
    ['    // {}\n    static const GatewayExceptionCode& {};\n'.format(row[-1], row[0]) for row in data_list])
output.write_text(header.format(push_back=push_back))

code = """#include "GatewayExceptionCode.h"
namespace anylink {{

{push_back}


GatewayExceptionCode::GatewayExceptionCode(int codeNumber, const std::string& codeName) {{
    std::string codeNumberString = std::to_string(codeNumber);
    int remainingLength = 4 - codeNumberString.length();
    for (int i = 0; i < remainingLength; i++) {{
        codeNumberString = "0" + codeNumberString;
    }}
    this->codeName = codeName;
    this->code = "GTW-" + codeNumberString;

}}

std::string GatewayExceptionCode::getCode() const {{
    return code;
}}

std::string GatewayExceptionCode::getCodeName() const {{
    return codeName;
}}

}} /* namespace anylink */

"""

# 위 header에 배열의 값 넣어주기
output = pathlib.Path(cpp_file_name)
sentence = '    const GatewayExceptionCode& GatewayExceptionCode::{} = GatewayExceptionCode({}, "{}");'
push_back = '\n'.join(
    [sentence.format(row[0], row[1], row[2].strip()) for row in data_list])
output.write_text(code.format(push_back=push_back))
