#include <EasyCrossPlatform.h>
#include <iostream>


int main(int argc, char** args) {
	//u8���������utf-8����.
	//˫б��IGNORE��ʾ�������������, ˫б��TRANSLIT��ʾ��������ͽ���һ��������ַ����滻.
	std::string StringToConvert = u8"�Ҳ�����";
	std::cout << "Original Text:" << StringToConvert << std::endl;
	try {
		std::cout << "Converted Text:" << EasyCrossPlatform::Parser::StringUtil::Charset::ConvertToCharset(StringToConvert, "UTF-8", "GBK//IGNORE") << std::endl;
	}
	catch (std::runtime_error e) {
		std::cout << "Cannot Convert" << std::endl;
	}
	catch (std::invalid_argument e) {
		std::cout << "Convert Charset Not Supported" << std::endl;
	}

	system("pause");
	return 0;
}