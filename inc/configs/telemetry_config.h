#ifndef TELEMETRY_CONFIG_H
#define TELEMETRY_CONFIG_H

#include "telemetry_config.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace Configs
{
struct CanDevice
{
    std::string socket;
    std::string name;
    std::vector<std::string> networks;
    
    CanDevice() = default;
    CanDevice(const PbConfigs::CanDevice& protobuf);
    operator PbConfigs::CanDevice() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct GpsDevice
{
    std::string address;
    std::string mode;
    bool enabled;
    
    GpsDevice() = default;
    GpsDevice(const PbConfigs::GpsDevice& protobuf);
    operator PbConfigs::GpsDevice() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct Connection
{
    std::string ip;
    std::string port;
    std::string mode;
    std::string whoamiUrl;
    bool tlsEnabled;
    std::string cafile;
    std::string capath;
    std::string certfile;
    std::string keyfile;
    
    Connection() = default;
    Connection(const PbConfigs::Connection& protobuf);
    operator PbConfigs::Connection() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct ConnectionSettings
{
    bool enabled;
    bool downsampleEnabled;
    bool downsampleSkipData;
    int64_t downsampleMps;
    int64_t sendRate;
    bool sendSensorData;
    
    ConnectionSettings() = default;
    ConnectionSettings(const PbConfigs::ConnectionSettings& protobuf);
    operator PbConfigs::ConnectionSettings() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct TelemetryConfig
{
    bool cameraEnabled;
    bool generateCsv;
    Connection connection;
    ConnectionSettings connectionSettings;
    std::vector<CanDevice> canDevices;
    std::vector<GpsDevice> gpsDevices;
    
    TelemetryConfig() = default;
    TelemetryConfig(const PbConfigs::TelemetryConfig& protobuf);
    operator PbConfigs::TelemetryConfig() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif