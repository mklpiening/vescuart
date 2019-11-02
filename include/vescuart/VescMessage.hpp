#ifndef VESCMESSAGE_HPP
#define VESCMESSAGE_HPP

#include <vector>
#include <optional>

namespace vescuart
{

enum class VescMessageType
{
    version,
    jumpToBootloader,
    eraseNewApp,
    writeNewAppData,
    getValues,
    setDuty,
    setCurrent,
    setCurrentBrake,
    setRpm,
    setPos,
    setHandbrake,
    setDetect,
    setServoPos,
    setMotorConfig,
    getMotorConfig,
    getMotorConfigDefault,
    setAppConfig,
    getAppConfig,
    getAppConfigDefault,
    samplePrint,
    terminalCommand,
    print,
    rotorPosition,
    eperimentSample,
    detectMotorParam,
    detectMotorRightLeft,
    detectMotorFluxLinkage,
    detectEncoder,
    detectHallFoc,
    reboot,
    alive,
    getDecodedPpm,
    getDecodedAdc,
    getDecodedChuk,
    forwardCan,
    setChuckData,
    customAppData,
    nrfStartPairing,
    gpdSetFsw,
    gpdBufferNotify,
    gpdBufferSizeLeft,
    gpdFillBuffer,
    gpdOutputSample,
    gpdSetMode,
    gpdFillBuffer8Int,
    gpdFillBuffer16Int,
    gpdSetBufferIntScale,
    getValuesSetup,
    setMotorConfigTemp,
    setMotorConfigTempSetup,
    getValuesSelective,
    getValuesSetupSelective,
    extNrfPresent,
    extNrfEsbSetChAddr,
    extNrfEsbSendData,
    extNrfEsbRxData,
    extNrfSetEnabled,
    detectMotorFluxLinkageOpenloop,
    detectApplyAllFoc,
    jumpToBootloaderAllCan,
    eraseNewAppAllCan,
    writeNewAppDataAllCan,
    pingCan,
    appDisableOutput,
    terminalCmdSync,
    getImuData,
    bmConnect,
    bmEraseFlashAll,
    bmWriteFlash,
    bmReboot,
    bmDisconnect,
    bmMapPinsDefault,
    bmMapPinsNrf5x,
    eraseBootloader,
    eraseBootloaderAllCan,
    pilotInit,
    pilotData,
    pilotAddGraph,
    pilotSetGraph,
    getDecodedBalance,
    bmMemRead,
};

class VescMessage : public std::vector<uint8_t>
{
  public:
    VescMessage() {}

    VescMessage(VescMessageType type);

    template<typename T>
    void add(T data);

    void addMessageType(VescMessageType type);

    void addForwardCan(std::optional<int> canId);
};

#include "vescuart/VescMessage.tcc"

} // namespace vescuart

#endif
