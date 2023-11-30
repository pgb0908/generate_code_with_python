#pragma once

#include <string>
#include "ExceptionCode.h"

namespace anylink {
class GatewayExceptionCode: public ExceptionCode {
private:
    std::string codeName;
    std::string code;

public:
    GatewayExceptionCode(int codeNumber, const std::string& codeName);
    virtual ~GatewayExceptionCode() = default;
    std::string getCode() const override;
    std::string getCodeName() const override;

public:
    // GWT-0000 : Gateway 알수없는 예외                             
    static const GatewayExceptionCode& GATEWAY_UNEXPECTED                                  ;

    // GWT-0001 : Gateway 가 모종의 이유로 커넥션을 끊어버린 경우 반환되는 코드.
    static const GatewayExceptionCode& GATEWAY_CHANNEL_CLOSED                              ;

    // GWT-0002 : Gateway 가 아직 Handshake 를 하지 않았음에도 Gateway 정보를 가져오는 등의 작업을 하려는 경우 반환되는 코드.
    static const GatewayExceptionCode& GATEWAY_YET_HANDSHAKED                              ;

    // GWT-1000 : Outbound 호출을 시도하려고 하나 연결된 Adapter 의 OutboundChannel 이 존재하지 않는 경우 반환되는 코드.
    static const GatewayExceptionCode& GATEWAY_OUTBOUND_CHANNEL_NOT_EXIST                  ;

    // GTW-1001 : Outbound가 존재하지않음
    static const GatewayExceptionCode& GATEWAY_OUTBOUND_NOT_EXIST                          ;

    // GTW-1002 : unmarshal 실패
    static const GatewayExceptionCode& GATEWAY_UNMARSHAL_FAIL                              ;

    // GTW-1003 : context를 만들 수 없었다
    static const GatewayExceptionCode& GATEWAY_CONTEXT_CREATE_FAIL                         ;

    // GTW-1004 : connection fail
    static const GatewayExceptionCode& GATEWAY_CONNECTION_FAIL                             ;

    // GTW-1005 : endpoint definition이 존재하지 않음
    static const GatewayExceptionCode& GATEWAY_ENDPOINT_DEF_NOT_EXIST                      ;

    // GTW-1006 : serviceGroup이 존재하지 않음
    static const GatewayExceptionCode& GATEWAY_SERVICEGROUP_NOT_EXIST                      ;

    // GTW-1007 : endpoint가 존재하지 않음
    static const GatewayExceptionCode& GATEWAY_ENDPOINT_NOT_EXIST                          ;

    // GTW-1008 : Decrypt 실패
    static const GatewayExceptionCode& GATEWAY_DECRYPT_FAIL                                ;

    // GTW-1009 : Encrypt 실패
    static const GatewayExceptionCode& GATEWAY_ENCRYPT_FAIL                                ;

    // GTW-1010 : Marshal 실패
    static const GatewayExceptionCode& GATEWAY_MARSHAL_FAIL                                ;

    // GTW-1011 : Mapping 실패
    static const GatewayExceptionCode& GATEWAY_MAPPING_FAIL                                ;

    // GTW-1012 : Bus에서 받은 Data Unmarshal 실패
    static const GatewayExceptionCode& GATEWAY_BUS_DATA_UNMARSHAL_FAIL                     ;

    // GTW-1013 : endpoint connection으로 write가 실패
    static const GatewayExceptionCode& GATEWAY_ENDPOINT_CONNECTION_WRITE_FAIL              ;

    // GTW-1014 : bus와의 커넥션 실패
    static const GatewayExceptionCode& GATEWAY_BUS_CONNECTION_FAIL                         ;

    // GTW-1015 : Outbound시 Request Message get 실패
    static const GatewayExceptionCode& GATEWAY_GET_REQUEST_MESSAGE_FAIL                    ;

    // GTW-1016 : Running 중이 아닌 endpoint에 요청이 들어왔을 경우
    static const GatewayExceptionCode& GATEWAY_ENDPOINT_NOT_RUNNING                        ;

    // GTW-1017 : Outbound 서비스 처리 시 ServiceName이 잘못 들어온 경우
    static const GatewayExceptionCode& GATEWAY_SERVICENAME_NOT_AVAILABLE                   ;

    // GTW-1018 : 어플리케이션이 존재하지 않음
    static const GatewayExceptionCode& GATEWAY_APPLICATION_NOT_EXIST                       ;

    // GTW-1019 : 서비스 호출 시 유효하지 않은 인자가 들어왔을 때
    static const GatewayExceptionCode& GATEWAY_SERVICE_INVALID_ARGUMENTS                   ;

    // GTW-1020 : 최대값을 초과한 연결을 시도했을때 나는 에러
    static const GatewayExceptionCode& GATEWAY_EXCEEDING_MAXIMUM_CONNTIONS_EXCEPTION       ;

    // GTW-1021 : 메시지 바운더리가 설정되지않음
    static const GatewayExceptionCode& GATEWAY_NOT_SET_BOUNDARY_EXCEPTION                  ;

    // GTW-1022 : 모종의 이유로 요청 컨텍스트가 지워짐 (외부에서 채널을 끊는 등)
    static const GatewayExceptionCode& GATEWAY_REMOVE_REQUEST_CONTEXT                      ;

    // GTW-1023 : 파싱룰이 정의되어있지않음
    static const GatewayExceptionCode& GATEWAY_PARSINGRULE_NOT_EXIST_EXCEPTION             ;

    // GTW-1024 : 맵핑룰이 정의되어있지않음
    static const GatewayExceptionCode& GATEWAY_MAPPINGRULE_NOT_EXIST_EXCEPTION             ;

    // GTW-1025 : 엔드포인트 그룹이 비어있음
    static const GatewayExceptionCode& GATEWAY_ENDPOINT_GROUP_IS_EMPTY                     ;

    // GTW-1026 : PreProcess auth fail
    static const GatewayExceptionCode& GATEWAY_PREPROCESS_AUTH_FAIL                        ;

    // GTW-1027 : PreProcess qos fail
    static const GatewayExceptionCode& GATEWAY_PREPROCESS_QOS_FAIL                         ;

    // GTW-1028 : socket read시 리턴 값이 0보다 작음
    static const GatewayExceptionCode& GATEWAY_READSIZE_BELOW_ZERO                         ;

    // GTW-1029 : 룰을 찾을 수 없을때
    static const GatewayExceptionCode& GATEWAY_RULE_NOT_EXIST_EXCEPTION                    ;

    // GTW-1030 : 미정의 행동
    static const GatewayExceptionCode& GATEWAY_UNDEFINED_BEHAVIOR_EXCEPTION                ;

    // GTW-1031 : 지원하지않는 SSL 파일 포맷
    static const GatewayExceptionCode& GATEWAY_UNSUPPORTED_SSL_FILE_FORMAT_EXCEPTION       ;

    // GTW-1032 : SSL 초기화 실패
    static const GatewayExceptionCode& GATEWAY_SSL_INIT_FAIL_EXCEPTION                     ;

    // GTW-1033 : 이미 read이벤트를 기다리고 있는 스트림 룰이 있음
    static const GatewayExceptionCode& GATEWAY_ALREADY_WAIT_STREAM_RULE_EXCEPTION          ;

    // GTW-1034 : 메세지가 정의되어있지않음
    static const GatewayExceptionCode& GATEWAY_MESSAGE_NOT_EXIST_EXCEPTION                 ;

    // GTW-1035 : 룰체인을 생성하지 못했음
    static const GatewayExceptionCode& GATEWAY_RULECHAIN_NOT_EXIST_EXCEPTION               ;

    // GTW-1036 : 서비스가 OFF되어있음
    static const GatewayExceptionCode& GATEWAY_SERVICE_OFF_EXCEPTION                       ;

    // GTW-1037 : 스레드풀의 큐가 가득 참
    static const GatewayExceptionCode& GATEWAY_THREAD_QUEUE_EXPLODE_EXCEPTION              ;

    // GTW-2001 : TCP write 에러
    static const GatewayExceptionCode& GATEWAY_TCP_WRITE_EXCEPTION                         ;

    // GTW-2002 : TCP connection Close 에러
    static const GatewayExceptionCode& GATEWAY_TCP_CONNECTION_CLOSE_EXCEPTION              ;

    // GTW-3001 : HTTP response code 가 300번 대
    static const GatewayExceptionCode& GATEWAY_HTTP_REDIRECT_RESPONSE                      ;

    // GTW-3002 : HTTP response code 가 400번 대
    static const GatewayExceptionCode& GATEWAY_HTTP_CLIENT_ERROR_RESPONSE                  ;

    // GTW-3003 : HTTP response code 가 500번 대
    static const GatewayExceptionCode& GATEWAY_HTTP_SERVER_ERROR_RESPONSE                  ;

    // GTW-3004 : HTTP response code 가 500번대 이상
    static const GatewayExceptionCode& GATEWAY_HTTP_UNKNOWN_ERROR_RESPONSE                 ;

    // GTW-3005 : HTTP 아웃바운드 url 이 잘못되었을 때
    static const GatewayExceptionCode& GATEWAY_HTTP_URL_ERROR                              ;

    // GTW-3006 : HTTP client 메세지 전송이 실패했을 때
    static const GatewayExceptionCode& GATEWAY_HTTP_CLIENT_EXECUTE_FAIL                    ;

    // GTW-3007 : HTTP client 연결이 실패했을때
    static const GatewayExceptionCode& GATEWAY_HTTP_CONNECTION_REFUSE                      ;

    // GTW-4001 : TMAX write 에러
    static const GatewayExceptionCode& GATEWAY_TMAX_WRITE_EXCEPTION                        ;

    // GTW-4002 : TMAX connection Close 에러
    static const GatewayExceptionCode& GATEWAY_TMAX_CONNECTION_CLOSE_EXCEPTION             ;

    // GTW-5001 : FILE No Permission Exception
    static const GatewayExceptionCode& GATEWAY_FILE_NO_PERMISSTION_EXCEPTION               ;

    // GTW-6001 : API 매칭 되는 조건을 찾을 수 없음
    static const GatewayExceptionCode& GATEWAY_API_NO_MATCHING_CONDITION_EXCEPTION         ;

    // GTW-6002 : API 라우팅 이름을 설정하지 않았음
    static const GatewayExceptionCode& GATEWAY_API_ROUTE_NAME_EMPTY_EXCEPTION              ;

    // GTW-6003 : API 인증 실패
    static const GatewayExceptionCode& GATEWAY_API_AUTHENTICATION_FAIL_EXCEPTION           ;

    // GTW-6004 : API qos 실패
    static const GatewayExceptionCode& GATEWAY_API_QOS_FAIL_EXCEPTION                      ;

    // GTW-6005 : API qos 실패
    static const GatewayExceptionCode& GATEWAY_API_CIRCUIT_BREAK_OPEN_EXCEPTION            ;

    // GTW-6006 : Allow Deny 실패
    static const GatewayExceptionCode& GATEWAY_API_ALLOW_DENY_FAIL_EXCEPTION               ;

    // GTW-6007 : API 인가 실패
    static const GatewayExceptionCode& GATEWAY_API_AUTHORIZATION_FAIL_EXCEPTION            ;

    // GTW-6008 : 거래제한 조건이 만족되었을 때 발생하는 에러
    static const GatewayExceptionCode& GATEWAY_TRANSACTION_DENY_EXCEPTION                  ;

    // GTW-6009 : API 요청 파라미터가 만족되지않았을때 발생하는 에러
    static const GatewayExceptionCode& GATEWAY_API_PARAMETER_REQUIRE_EXCEPTION             ;

    // GTW-6010 : API ThreadPool을 찾을 수 없음
    static const GatewayExceptionCode& GATEWAY_API_THREADPOOL_NOT_EXIST                    ;

    // GTW-7002 : Monitoring Transaction Thread가 connection을 맺고 있는 HyperLoader와 HealthCheck가 실패했을 때
    static const GatewayExceptionCode& MONITOR_HEALTH_CHECK_FAIL                           ;

    // GTW-8400 : 
    static const GatewayExceptionCode& GATEWAY_EVENT_LAYER_IPC_FAILED                      ;

    // GTW-9001 : PO에서 에러 응답이 돌아옴
    static const GatewayExceptionCode& GATEWAY_PO_ERROR_RESPONSE                           ;


};
} /* namespace anylink */
