#include <gtest/gtest.h>
#include <string>
#include <iostream>

class UartDriver {
private:
    int baudRate;
    int dataBits;
    int stopBits;
    bool parityEnabled;
    UartDriver() = default;  // private 생성자

public:
    // 복사 및 할당 방지
    UartDriver(const UartDriver&) = delete;
    UartDriver& operator=(const UartDriver&) = delete;

    static UartDriver& getInstance() {
        static UartDriver instance;
        std::cout << "Size of UartDriver: " << sizeof(instance) << " bytes" << std::endl;
        return instance;
    }

    bool init(const std::string& port, int baudRate) {
        // 실제 UART 초기화 코드
        return true;
    }

    bool send(const std::string& data) {
        // 실제 데이터 전송 코드
        return true;
    }

    std::string receive() {
        // 실제 데이터 수신 코드
        return "received data";
    }
};

// UART 드라이버 테스트
class UartDriverTest : public ::testing::Test {
protected:
    void SetUp() override {
        uart = &UartDriver::getInstance();
    }

    UartDriver* uart;
};

TEST_F(UartDriverTest, InitializationTest) {
    EXPECT_TRUE(uart->init("/dev/ttyUSB0", 115200));
}

TEST_F(UartDriverTest, SendTest) {
    EXPECT_TRUE(uart->send("Hello UART"));
}

TEST_F(UartDriverTest, ReceiveTest) {
    EXPECT_FALSE(uart->receive().empty());
}

TEST_F(UartDriverTest, SingletonTest) {
    UartDriver& uart1 = UartDriver::getInstance();
    UartDriver& uart2 = UartDriver::getInstance();
    EXPECT_EQ(&uart1, &uart2);
}

int main(int argc, char **argv) {
    // 첫 번째 인스턴스 가져오기
    UartDriver& uart1 = UartDriver::getInstance();
    std::cout << "First instance address: " << &uart1 << std::endl;

    // 두 번째 인스턴스 가져오기
    UartDriver& uart2 = UartDriver::getInstance();
    std::cout << "Second instance address: " << &uart2 << std::endl;

    // Google Test 실행
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}