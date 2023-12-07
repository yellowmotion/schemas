#include "configs/telemetry_config.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace Configs
{
CanDevice::CanDevice(const PbConfigs::CanDevice& protobuf) {
    socket = protobuf.socket();
    name = protobuf.name();
    networks = {protobuf.networks().begin(), protobuf.networks().end()};
}

CanDevice::operator PbConfigs::CanDevice() const {
    PbConfigs::CanDevice ret;
    ret.set_socket(socket);
    ret.set_name(name);
    *(ret.mutable_networks()) = {networks.begin(), networks.end()};
    return ret;
}

std::string CanDevice::serializeAsJsonString() const {
    PbConfigs::CanDevice protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string CanDevice::serializeAsProtobufString() const {
    PbConfigs::CanDevice protobuf(*this);
    return protobuf.SerializeAsString();
}

bool CanDevice::deserializeFromJsonString(const std::string& str) {
    PbConfigs::CanDevice protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool CanDevice::deserializeFromProtobufString(const std::string& str) {
    PbConfigs::CanDevice protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

GpsDevice::GpsDevice(const PbConfigs::GpsDevice& protobuf) {
    address = protobuf.address();
    mode = protobuf.mode();
    enabled = protobuf.enabled();
}

GpsDevice::operator PbConfigs::GpsDevice() const {
    PbConfigs::GpsDevice ret;
    ret.set_address(address);
    ret.set_mode(mode);
    ret.set_enabled(enabled);
    return ret;
}

std::string GpsDevice::serializeAsJsonString() const {
    PbConfigs::GpsDevice protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string GpsDevice::serializeAsProtobufString() const {
    PbConfigs::GpsDevice protobuf(*this);
    return protobuf.SerializeAsString();
}

bool GpsDevice::deserializeFromJsonString(const std::string& str) {
    PbConfigs::GpsDevice protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool GpsDevice::deserializeFromProtobufString(const std::string& str) {
    PbConfigs::GpsDevice protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

Connection::Connection(const PbConfigs::Connection& protobuf) {
    ip = protobuf.ip();
    port = protobuf.port();
    mode = protobuf.mode();
    whoamiUrl = protobuf.whoamiurl();
    tlsEnabled = protobuf.tlsenabled();
    cafile = protobuf.cafile();
    capath = protobuf.capath();
    certfile = protobuf.certfile();
    keyfile = protobuf.keyfile();
}

Connection::operator PbConfigs::Connection() const {
    PbConfigs::Connection ret;
    ret.set_ip(ip);
    ret.set_port(port);
    ret.set_mode(mode);
    ret.set_whoamiurl(whoamiUrl);
    ret.set_tlsenabled(tlsEnabled);
    ret.set_cafile(cafile);
    ret.set_capath(capath);
    ret.set_certfile(certfile);
    ret.set_keyfile(keyfile);
    return ret;
}

std::string Connection::serializeAsJsonString() const {
    PbConfigs::Connection protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Connection::serializeAsProtobufString() const {
    PbConfigs::Connection protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Connection::deserializeFromJsonString(const std::string& str) {
    PbConfigs::Connection protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Connection::deserializeFromProtobufString(const std::string& str) {
    PbConfigs::Connection protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

ConnectionSettings::ConnectionSettings(const PbConfigs::ConnectionSettings& protobuf) {
    enabled = protobuf.enabled();
    downsampleEnabled = protobuf.downsampleenabled();
    downsampleSkipData = protobuf.downsampleskipdata();
    downsampleMps = protobuf.downsamplemps();
    sendRate = protobuf.sendrate();
    sendSensorData = protobuf.sendsensordata();
}

ConnectionSettings::operator PbConfigs::ConnectionSettings() const {
    PbConfigs::ConnectionSettings ret;
    ret.set_enabled(enabled);
    ret.set_downsampleenabled(downsampleEnabled);
    ret.set_downsampleskipdata(downsampleSkipData);
    ret.set_downsamplemps(downsampleMps);
    ret.set_sendrate(sendRate);
    ret.set_sendsensordata(sendSensorData);
    return ret;
}

std::string ConnectionSettings::serializeAsJsonString() const {
    PbConfigs::ConnectionSettings protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string ConnectionSettings::serializeAsProtobufString() const {
    PbConfigs::ConnectionSettings protobuf(*this);
    return protobuf.SerializeAsString();
}

bool ConnectionSettings::deserializeFromJsonString(const std::string& str) {
    PbConfigs::ConnectionSettings protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool ConnectionSettings::deserializeFromProtobufString(const std::string& str) {
    PbConfigs::ConnectionSettings protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

TelemetryConfig::TelemetryConfig(const PbConfigs::TelemetryConfig& protobuf) {
    cameraEnabled = protobuf.cameraenabled();
    generateCsv = protobuf.generatecsv();
    connection = protobuf.connection();
    connectionSettings = protobuf.connectionsettings();
    canDevices = {protobuf.candevices().begin(), protobuf.candevices().end()};
    gpsDevices = {protobuf.gpsdevices().begin(), protobuf.gpsdevices().end()};
}

TelemetryConfig::operator PbConfigs::TelemetryConfig() const {
    PbConfigs::TelemetryConfig ret;
    ret.set_cameraenabled(cameraEnabled);
    ret.set_generatecsv(generateCsv);
    *(ret.mutable_connection()) = connection;
    *(ret.mutable_connectionsettings()) = connectionSettings;
    *(ret.mutable_candevices()) = {canDevices.begin(), canDevices.end()};
    *(ret.mutable_gpsdevices()) = {gpsDevices.begin(), gpsDevices.end()};
    return ret;
}

std::string TelemetryConfig::serializeAsJsonString() const {
    PbConfigs::TelemetryConfig protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string TelemetryConfig::serializeAsProtobufString() const {
    PbConfigs::TelemetryConfig protobuf(*this);
    return protobuf.SerializeAsString();
}

bool TelemetryConfig::deserializeFromJsonString(const std::string& str) {
    PbConfigs::TelemetryConfig protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool TelemetryConfig::deserializeFromProtobufString(const std::string& str) {
    PbConfigs::TelemetryConfig protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}