/**********************************************************************
 *  Copyright (c) 2008-2015, Alliance for Sustainable Energy.
 *  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 **********************************************************************/

#include "CoilHeatingDXMultiSpeed.hpp"
#include "CoilHeatingDXMultiSpeed_Impl.hpp"

#include "Schedule.hpp"
#include "Schedule_Impl.hpp"
#include "CurveBiquadratic.hpp"
#include "CurveBiquadratic_Impl.hpp"
#include "ScheduleTypeLimits.hpp"
#include "ScheduleTypeRegistry.hpp"

#include <utilities/idd/IddFactory.hxx>
#include <utilities/idd/OS_Coil_Heating_DX_MultiSpeed_FieldEnums.hxx>

#include <utilities/idd/IddEnums.hxx>
#include "../utilities/units/Unit.hpp"
#include "../utilities/core/Assert.hpp"

namespace openstudio {
namespace model {

namespace detail {

  CoilHeatingDXMultiSpeed_Impl::CoilHeatingDXMultiSpeed_Impl(const IdfObject& idfObject,
                                                             Model_Impl* model,
                                                             bool keepHandle)
    : StraightComponent_Impl(idfObject,model,keepHandle)
  {
    OS_ASSERT(idfObject.iddObject().type() == CoilHeatingDXMultiSpeed::iddObjectType());
  }

  CoilHeatingDXMultiSpeed_Impl::CoilHeatingDXMultiSpeed_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                                             Model_Impl* model,
                                                             bool keepHandle)
    : StraightComponent_Impl(other,model,keepHandle)
  {
    OS_ASSERT(other.iddObject().type() == CoilHeatingDXMultiSpeed::iddObjectType());
  }

  CoilHeatingDXMultiSpeed_Impl::CoilHeatingDXMultiSpeed_Impl(const CoilHeatingDXMultiSpeed_Impl& other,
                                                             Model_Impl* model,
                                                             bool keepHandle)
    : StraightComponent_Impl(other,model,keepHandle)
  {}

  const std::vector<std::string>& CoilHeatingDXMultiSpeed_Impl::outputVariableNames() const
  {
    static std::vector<std::string> result;
    if (result.empty()){
    }
    return result;
  }

  IddObjectType CoilHeatingDXMultiSpeed_Impl::iddObjectType() const {
    return CoilHeatingDXMultiSpeed::iddObjectType();
  }

  std::vector<ScheduleTypeKey> CoilHeatingDXMultiSpeed_Impl::getScheduleTypeKeys(const Schedule& schedule) const
  {
    // TODO: Check schedule display names.
    std::vector<ScheduleTypeKey> result;
    UnsignedVector fieldIndices = getSourceIndices(schedule.handle());
    UnsignedVector::const_iterator b(fieldIndices.begin()), e(fieldIndices.end());
    if (std::find(b,e,OS_Coil_Heating_DX_MultiSpeedFields::AvailabilityScheduleName) != e)
    {
      result.push_back(ScheduleTypeKey("CoilHeatingDXMultiSpeed","Availability"));
    }
    return result;
  }

  unsigned CoilHeatingDXMultiSpeed_Impl::inletPort() {
    return OS_Coil_Heating_DX_MultiSpeedFields::AirInletNodeName;
  }

  unsigned CoilHeatingDXMultiSpeed_Impl::outletPort() {
    return OS_Coil_Heating_DX_MultiSpeedFields::AirOutletNodeName;
  }

  boost::optional<Schedule> CoilHeatingDXMultiSpeed_Impl::availabilitySchedule() const {
    return getObject<ModelObject>().getModelObjectTarget<Schedule>(OS_Coil_Heating_DX_MultiSpeedFields::AvailabilityScheduleName);
  }

  double CoilHeatingDXMultiSpeed_Impl::minimumOutdoorDryBulbTemperatureforCompressorOperation() const {
    boost::optional<double> value = getDouble(OS_Coil_Heating_DX_MultiSpeedFields::MinimumOutdoorDryBulbTemperatureforCompressorOperation,true);
    OS_ASSERT(value);
    return value.get();
  }

  boost::optional<double> CoilHeatingDXMultiSpeed_Impl::outdoorDryBulbTemperaturetoTurnOnCompressor() const {
    return getDouble(OS_Coil_Heating_DX_MultiSpeedFields::OutdoorDryBulbTemperaturetoTurnOnCompressor,true);
  }

  double CoilHeatingDXMultiSpeed_Impl::crankcaseHeaterCapacity() const {
    boost::optional<double> value = getDouble(OS_Coil_Heating_DX_MultiSpeedFields::CrankcaseHeaterCapacity,true);
    OS_ASSERT(value);
    return value.get();
  }

  double CoilHeatingDXMultiSpeed_Impl::maximumOutdoorDryBulbTemperatureforCrankcaseHeaterOperation() const {
    boost::optional<double> value = getDouble(OS_Coil_Heating_DX_MultiSpeedFields::MaximumOutdoorDryBulbTemperatureforCrankcaseHeaterOperation,true);
    OS_ASSERT(value);
    return value.get();
  }

  boost::optional<CurveBiquadratic> CoilHeatingDXMultiSpeed_Impl::defrostEnergyInputRatioFunctionofTemperatureCurve() const {
    return getObject<ModelObject>().getModelObjectTarget<CurveBiquadratic>(OS_Coil_Heating_DX_MultiSpeedFields::DefrostEnergyInputRatioFunctionofTemperatureCurveName);
  }

  double CoilHeatingDXMultiSpeed_Impl::maximumOutdoorDryBulbTemperatureforDefrostOperation() const {
    boost::optional<double> value = getDouble(OS_Coil_Heating_DX_MultiSpeedFields::MaximumOutdoorDryBulbTemperatureforDefrostOperation,true);
    OS_ASSERT(value);
    return value.get();
  }

  std::string CoilHeatingDXMultiSpeed_Impl::defrostStrategy() const {
    boost::optional<std::string> value = getString(OS_Coil_Heating_DX_MultiSpeedFields::DefrostStrategy,true);
    OS_ASSERT(value);
    return value.get();
  }

  std::string CoilHeatingDXMultiSpeed_Impl::defrostControl() const {
    boost::optional<std::string> value = getString(OS_Coil_Heating_DX_MultiSpeedFields::DefrostControl,true);
    OS_ASSERT(value);
    return value.get();
  }

  double CoilHeatingDXMultiSpeed_Impl::defrostTimePeriodFraction() const {
    boost::optional<double> value = getDouble(OS_Coil_Heating_DX_MultiSpeedFields::DefrostTimePeriodFraction,true);
    OS_ASSERT(value);
    return value.get();
  }

  boost::optional<double> CoilHeatingDXMultiSpeed_Impl::resistiveDefrostHeaterCapacity() const {
    return getDouble(OS_Coil_Heating_DX_MultiSpeedFields::ResistiveDefrostHeaterCapacity,true);
  }

  bool CoilHeatingDXMultiSpeed_Impl::isResistiveDefrostHeaterCapacityAutosized() const {
    bool result = false;
    boost::optional<std::string> value = getString(OS_Coil_Heating_DX_MultiSpeedFields::ResistiveDefrostHeaterCapacity, true);
    if (value) {
      result = openstudio::istringEqual(value.get(), "autosize");
    }
    return result;
  }

  bool CoilHeatingDXMultiSpeed_Impl::applyPartLoadFractiontoSpeedsGreaterthan1() const {
    boost::optional<std::string> value = getString(OS_Coil_Heating_DX_MultiSpeedFields::ApplyPartLoadFractiontoSpeedsGreaterthan1,true);
    OS_ASSERT(value);
    return openstudio::istringEqual(value.get(), "Yes");
  }

  std::string CoilHeatingDXMultiSpeed_Impl::fuelType() const {
    boost::optional<std::string> value = getString(OS_Coil_Heating_DX_MultiSpeedFields::FuelType,true);
    OS_ASSERT(value);
    return value.get();
  }

  int CoilHeatingDXMultiSpeed_Impl::regionnumberforCalculatingHSPF() const {
    boost::optional<int> value = getInt(OS_Coil_Heating_DX_MultiSpeedFields::RegionnumberforCalculatingHSPF,true);
    OS_ASSERT(value);
    return value.get();
  }

  bool CoilHeatingDXMultiSpeed_Impl::setAvailabilitySchedule(Schedule& schedule) {
    bool result = setSchedule(OS_Coil_Heating_DX_MultiSpeedFields::AvailabilityScheduleName,
                              "CoilHeatingDXMultiSpeed",
                              "Availability",
                              schedule);
    return result;
  }

  void CoilHeatingDXMultiSpeed_Impl::resetAvailabilitySchedule() {
    bool result = setString(OS_Coil_Heating_DX_MultiSpeedFields::AvailabilityScheduleName, "");
    OS_ASSERT(result);
  }

  void CoilHeatingDXMultiSpeed_Impl::setMinimumOutdoorDryBulbTemperatureforCompressorOperation(double minimumOutdoorDryBulbTemperatureforCompressorOperation) {
    bool result = setDouble(OS_Coil_Heating_DX_MultiSpeedFields::MinimumOutdoorDryBulbTemperatureforCompressorOperation, minimumOutdoorDryBulbTemperatureforCompressorOperation);
    OS_ASSERT(result);
  }

  void CoilHeatingDXMultiSpeed_Impl::setOutdoorDryBulbTemperaturetoTurnOnCompressor(boost::optional<double> outdoorDryBulbTemperaturetoTurnOnCompressor) {
    bool result(false);
    if (outdoorDryBulbTemperaturetoTurnOnCompressor) {
      result = setDouble(OS_Coil_Heating_DX_MultiSpeedFields::OutdoorDryBulbTemperaturetoTurnOnCompressor, outdoorDryBulbTemperaturetoTurnOnCompressor.get());
    }
    else {
      resetOutdoorDryBulbTemperaturetoTurnOnCompressor();
      result = true;
    }
    OS_ASSERT(result);
  }

  void CoilHeatingDXMultiSpeed_Impl::resetOutdoorDryBulbTemperaturetoTurnOnCompressor() {
    bool result = setString(OS_Coil_Heating_DX_MultiSpeedFields::OutdoorDryBulbTemperaturetoTurnOnCompressor, "");
    OS_ASSERT(result);
  }

  bool CoilHeatingDXMultiSpeed_Impl::setCrankcaseHeaterCapacity(double crankcaseHeaterCapacity) {
    bool result = setDouble(OS_Coil_Heating_DX_MultiSpeedFields::CrankcaseHeaterCapacity, crankcaseHeaterCapacity);
    return result;
  }

  bool CoilHeatingDXMultiSpeed_Impl::setMaximumOutdoorDryBulbTemperatureforCrankcaseHeaterOperation(double maximumOutdoorDryBulbTemperatureforCrankcaseHeaterOperation) {
    bool result = setDouble(OS_Coil_Heating_DX_MultiSpeedFields::MaximumOutdoorDryBulbTemperatureforCrankcaseHeaterOperation, maximumOutdoorDryBulbTemperatureforCrankcaseHeaterOperation);
    return result;
  }

  bool CoilHeatingDXMultiSpeed_Impl::setDefrostEnergyInputRatioFunctionofTemperatureCurve(const boost::optional<CurveBiquadratic>& curveBiquadratic) {
    bool result(false);
    if (curveBiquadratic) {
      result = setPointer(OS_Coil_Heating_DX_MultiSpeedFields::DefrostEnergyInputRatioFunctionofTemperatureCurveName, curveBiquadratic.get().handle());
    }
    else {
      resetDefrostEnergyInputRatioFunctionofTemperatureCurve();
      result = true;
    }
    return result;
  }

  void CoilHeatingDXMultiSpeed_Impl::resetDefrostEnergyInputRatioFunctionofTemperatureCurve() {
    bool result = setString(OS_Coil_Heating_DX_MultiSpeedFields::DefrostEnergyInputRatioFunctionofTemperatureCurveName, "");
    OS_ASSERT(result);
  }

  bool CoilHeatingDXMultiSpeed_Impl::setMaximumOutdoorDryBulbTemperatureforDefrostOperation(double maximumOutdoorDryBulbTemperatureforDefrostOperation) {
    bool result = setDouble(OS_Coil_Heating_DX_MultiSpeedFields::MaximumOutdoorDryBulbTemperatureforDefrostOperation, maximumOutdoorDryBulbTemperatureforDefrostOperation);
    return result;
  }

  bool CoilHeatingDXMultiSpeed_Impl::setDefrostStrategy(std::string defrostStrategy) {
    bool result = setString(OS_Coil_Heating_DX_MultiSpeedFields::DefrostStrategy, defrostStrategy);
    return result;
  }

  bool CoilHeatingDXMultiSpeed_Impl::setDefrostControl(std::string defrostControl) {
    bool result = setString(OS_Coil_Heating_DX_MultiSpeedFields::DefrostControl, defrostControl);
    return result;
  }

  bool CoilHeatingDXMultiSpeed_Impl::setDefrostTimePeriodFraction(double defrostTimePeriodFraction) {
    bool result = setDouble(OS_Coil_Heating_DX_MultiSpeedFields::DefrostTimePeriodFraction, defrostTimePeriodFraction);
    return result;
  }

  bool CoilHeatingDXMultiSpeed_Impl::setResistiveDefrostHeaterCapacity(boost::optional<double> resistiveDefrostHeaterCapacity) {
    bool result(false);
    if (resistiveDefrostHeaterCapacity) {
      result = setDouble(OS_Coil_Heating_DX_MultiSpeedFields::ResistiveDefrostHeaterCapacity, resistiveDefrostHeaterCapacity.get());
    }
    return result;
  }

  void CoilHeatingDXMultiSpeed_Impl::autosizeResistiveDefrostHeaterCapacity() {
    bool result = setString(OS_Coil_Heating_DX_MultiSpeedFields::ResistiveDefrostHeaterCapacity, "autosize");
    OS_ASSERT(result);
  }

  void CoilHeatingDXMultiSpeed_Impl::setApplyPartLoadFractiontoSpeedsGreaterthan1(bool applyPartLoadFractiontoSpeedsGreaterthan1) {
    setBooleanFieldValue(OS_Coil_Heating_DX_MultiSpeedFields::ApplyPartLoadFractiontoSpeedsGreaterthan1, applyPartLoadFractiontoSpeedsGreaterthan1);
  }

  bool CoilHeatingDXMultiSpeed_Impl::setFuelType(std::string fuelType) {
    bool result = setString(OS_Coil_Heating_DX_MultiSpeedFields::FuelType, fuelType);
    return result;
  }

  bool CoilHeatingDXMultiSpeed_Impl::setRegionnumberforCalculatingHSPF(int regionnumberforCalculatingHSPF) {
    bool result = setInt(OS_Coil_Heating_DX_MultiSpeedFields::RegionnumberforCalculatingHSPF, regionnumberforCalculatingHSPF);
    return result;
  }

} // detail

CoilHeatingDXMultiSpeed::CoilHeatingDXMultiSpeed(const Model& model)
  : StraightComponent(CoilHeatingDXMultiSpeed::iddObjectType(),model)
{
  OS_ASSERT(getImpl<detail::CoilHeatingDXMultiSpeed_Impl>());

  // TODO: Appropriately handle the following required object-list fields.
  //     OS_Coil_Heating_DX_MultiSpeedFields::AirInletNodeName
  //     OS_Coil_Heating_DX_MultiSpeedFields::AirOutletNodeName
  bool ok = true;
  // ok = setHandle();
  OS_ASSERT(ok);
  // ok = setAirInletNode();
  OS_ASSERT(ok);
  // ok = setAirOutletNode();
  OS_ASSERT(ok);
  // setMinimumOutdoorDryBulbTemperatureforCompressorOperation();
  // ok = setCrankcaseHeaterCapacity();
  OS_ASSERT(ok);
  // ok = setMaximumOutdoorDryBulbTemperatureforCrankcaseHeaterOperation();
  OS_ASSERT(ok);
  // ok = setMaximumOutdoorDryBulbTemperatureforDefrostOperation();
  OS_ASSERT(ok);
  // ok = setDefrostStrategy();
  OS_ASSERT(ok);
  // ok = setDefrostControl();
  OS_ASSERT(ok);
  // ok = setDefrostTimePeriodFraction();
  OS_ASSERT(ok);
  // ok = setResistiveDefrostHeaterCapacity();
  OS_ASSERT(ok);
  // setApplyPartLoadFractiontoSpeedsGreaterthan1();
  // ok = setFuelType();
  OS_ASSERT(ok);
  // ok = setRegionnumberforCalculatingHSPF();
  OS_ASSERT(ok);
}

IddObjectType CoilHeatingDXMultiSpeed::iddObjectType() {
  return IddObjectType(IddObjectType::OS_Coil_Heating_DX_MultiSpeed);
}

std::vector<std::string> CoilHeatingDXMultiSpeed::defrostStrategyValues() {
  return getIddKeyNames(IddFactory::instance().getObject(iddObjectType()).get(),
                        OS_Coil_Heating_DX_MultiSpeedFields::DefrostStrategy);
}

std::vector<std::string> CoilHeatingDXMultiSpeed::defrostControlValues() {
  return getIddKeyNames(IddFactory::instance().getObject(iddObjectType()).get(),
                        OS_Coil_Heating_DX_MultiSpeedFields::DefrostControl);
}

std::vector<std::string> CoilHeatingDXMultiSpeed::fuelTypeValues() {
  return getIddKeyNames(IddFactory::instance().getObject(iddObjectType()).get(),
                        OS_Coil_Heating_DX_MultiSpeedFields::FuelType);
}

boost::optional<Schedule> CoilHeatingDXMultiSpeed::availabilitySchedule() const {
  return getImpl<detail::CoilHeatingDXMultiSpeed_Impl>()->availabilitySchedule();
}

double CoilHeatingDXMultiSpeed::minimumOutdoorDryBulbTemperatureforCompressorOperation() const {
  return getImpl<detail::CoilHeatingDXMultiSpeed_Impl>()->minimumOutdoorDryBulbTemperatureforCompressorOperation();
}

boost::optional<double> CoilHeatingDXMultiSpeed::outdoorDryBulbTemperaturetoTurnOnCompressor() const {
  return getImpl<detail::CoilHeatingDXMultiSpeed_Impl>()->outdoorDryBulbTemperaturetoTurnOnCompressor();
}

double CoilHeatingDXMultiSpeed::crankcaseHeaterCapacity() const {
  return getImpl<detail::CoilHeatingDXMultiSpeed_Impl>()->crankcaseHeaterCapacity();
}

double CoilHeatingDXMultiSpeed::maximumOutdoorDryBulbTemperatureforCrankcaseHeaterOperation() const {
  return getImpl<detail::CoilHeatingDXMultiSpeed_Impl>()->maximumOutdoorDryBulbTemperatureforCrankcaseHeaterOperation();
}

boost::optional<CurveBiquadratic> CoilHeatingDXMultiSpeed::defrostEnergyInputRatioFunctionofTemperatureCurve() const {
  return getImpl<detail::CoilHeatingDXMultiSpeed_Impl>()->defrostEnergyInputRatioFunctionofTemperatureCurve();
}

double CoilHeatingDXMultiSpeed::maximumOutdoorDryBulbTemperatureforDefrostOperation() const {
  return getImpl<detail::CoilHeatingDXMultiSpeed_Impl>()->maximumOutdoorDryBulbTemperatureforDefrostOperation();
}

std::string CoilHeatingDXMultiSpeed::defrostStrategy() const {
  return getImpl<detail::CoilHeatingDXMultiSpeed_Impl>()->defrostStrategy();
}

std::string CoilHeatingDXMultiSpeed::defrostControl() const {
  return getImpl<detail::CoilHeatingDXMultiSpeed_Impl>()->defrostControl();
}

double CoilHeatingDXMultiSpeed::defrostTimePeriodFraction() const {
  return getImpl<detail::CoilHeatingDXMultiSpeed_Impl>()->defrostTimePeriodFraction();
}

boost::optional<double> CoilHeatingDXMultiSpeed::resistiveDefrostHeaterCapacity() const {
  return getImpl<detail::CoilHeatingDXMultiSpeed_Impl>()->resistiveDefrostHeaterCapacity();
}

bool CoilHeatingDXMultiSpeed::isResistiveDefrostHeaterCapacityAutosized() const {
  return getImpl<detail::CoilHeatingDXMultiSpeed_Impl>()->isResistiveDefrostHeaterCapacityAutosized();
}

bool CoilHeatingDXMultiSpeed::applyPartLoadFractiontoSpeedsGreaterthan1() const {
  return getImpl<detail::CoilHeatingDXMultiSpeed_Impl>()->applyPartLoadFractiontoSpeedsGreaterthan1();
}

std::string CoilHeatingDXMultiSpeed::fuelType() const {
  return getImpl<detail::CoilHeatingDXMultiSpeed_Impl>()->fuelType();
}

int CoilHeatingDXMultiSpeed::regionnumberforCalculatingHSPF() const {
  return getImpl<detail::CoilHeatingDXMultiSpeed_Impl>()->regionnumberforCalculatingHSPF();
}

bool CoilHeatingDXMultiSpeed::setAvailabilitySchedule(Schedule& schedule) {
  return getImpl<detail::CoilHeatingDXMultiSpeed_Impl>()->setAvailabilitySchedule(schedule);
}

void CoilHeatingDXMultiSpeed::resetAvailabilitySchedule() {
  getImpl<detail::CoilHeatingDXMultiSpeed_Impl>()->resetAvailabilitySchedule();
}

void CoilHeatingDXMultiSpeed::setMinimumOutdoorDryBulbTemperatureforCompressorOperation(double minimumOutdoorDryBulbTemperatureforCompressorOperation) {
  getImpl<detail::CoilHeatingDXMultiSpeed_Impl>()->setMinimumOutdoorDryBulbTemperatureforCompressorOperation(minimumOutdoorDryBulbTemperatureforCompressorOperation);
}

void CoilHeatingDXMultiSpeed::setOutdoorDryBulbTemperaturetoTurnOnCompressor(double outdoorDryBulbTemperaturetoTurnOnCompressor) {
  getImpl<detail::CoilHeatingDXMultiSpeed_Impl>()->setOutdoorDryBulbTemperaturetoTurnOnCompressor(outdoorDryBulbTemperaturetoTurnOnCompressor);
}

void CoilHeatingDXMultiSpeed::resetOutdoorDryBulbTemperaturetoTurnOnCompressor() {
  getImpl<detail::CoilHeatingDXMultiSpeed_Impl>()->resetOutdoorDryBulbTemperaturetoTurnOnCompressor();
}

bool CoilHeatingDXMultiSpeed::setCrankcaseHeaterCapacity(double crankcaseHeaterCapacity) {
  return getImpl<detail::CoilHeatingDXMultiSpeed_Impl>()->setCrankcaseHeaterCapacity(crankcaseHeaterCapacity);
}

bool CoilHeatingDXMultiSpeed::setMaximumOutdoorDryBulbTemperatureforCrankcaseHeaterOperation(double maximumOutdoorDryBulbTemperatureforCrankcaseHeaterOperation) {
  return getImpl<detail::CoilHeatingDXMultiSpeed_Impl>()->setMaximumOutdoorDryBulbTemperatureforCrankcaseHeaterOperation(maximumOutdoorDryBulbTemperatureforCrankcaseHeaterOperation);
}

bool CoilHeatingDXMultiSpeed::setDefrostEnergyInputRatioFunctionofTemperatureCurve(const CurveBiquadratic& curveBiquadratic) {
  return getImpl<detail::CoilHeatingDXMultiSpeed_Impl>()->setDefrostEnergyInputRatioFunctionofTemperatureCurve(curveBiquadratic);
}

void CoilHeatingDXMultiSpeed::resetDefrostEnergyInputRatioFunctionofTemperatureCurve() {
  getImpl<detail::CoilHeatingDXMultiSpeed_Impl>()->resetDefrostEnergyInputRatioFunctionofTemperatureCurve();
}

bool CoilHeatingDXMultiSpeed::setMaximumOutdoorDryBulbTemperatureforDefrostOperation(double maximumOutdoorDryBulbTemperatureforDefrostOperation) {
  return getImpl<detail::CoilHeatingDXMultiSpeed_Impl>()->setMaximumOutdoorDryBulbTemperatureforDefrostOperation(maximumOutdoorDryBulbTemperatureforDefrostOperation);
}

bool CoilHeatingDXMultiSpeed::setDefrostStrategy(std::string defrostStrategy) {
  return getImpl<detail::CoilHeatingDXMultiSpeed_Impl>()->setDefrostStrategy(defrostStrategy);
}

bool CoilHeatingDXMultiSpeed::setDefrostControl(std::string defrostControl) {
  return getImpl<detail::CoilHeatingDXMultiSpeed_Impl>()->setDefrostControl(defrostControl);
}

bool CoilHeatingDXMultiSpeed::setDefrostTimePeriodFraction(double defrostTimePeriodFraction) {
  return getImpl<detail::CoilHeatingDXMultiSpeed_Impl>()->setDefrostTimePeriodFraction(defrostTimePeriodFraction);
}

bool CoilHeatingDXMultiSpeed::setResistiveDefrostHeaterCapacity(double resistiveDefrostHeaterCapacity) {
  return getImpl<detail::CoilHeatingDXMultiSpeed_Impl>()->setResistiveDefrostHeaterCapacity(resistiveDefrostHeaterCapacity);
}

void CoilHeatingDXMultiSpeed::autosizeResistiveDefrostHeaterCapacity() {
  getImpl<detail::CoilHeatingDXMultiSpeed_Impl>()->autosizeResistiveDefrostHeaterCapacity();
}

void CoilHeatingDXMultiSpeed::setApplyPartLoadFractiontoSpeedsGreaterthan1(bool applyPartLoadFractiontoSpeedsGreaterthan1) {
  getImpl<detail::CoilHeatingDXMultiSpeed_Impl>()->setApplyPartLoadFractiontoSpeedsGreaterthan1(applyPartLoadFractiontoSpeedsGreaterthan1);
}

bool CoilHeatingDXMultiSpeed::setFuelType(std::string fuelType) {
  return getImpl<detail::CoilHeatingDXMultiSpeed_Impl>()->setFuelType(fuelType);
}

bool CoilHeatingDXMultiSpeed::setRegionnumberforCalculatingHSPF(int regionnumberforCalculatingHSPF) {
  return getImpl<detail::CoilHeatingDXMultiSpeed_Impl>()->setRegionnumberforCalculatingHSPF(regionnumberforCalculatingHSPF);
}

/// @cond
CoilHeatingDXMultiSpeed::CoilHeatingDXMultiSpeed(std::shared_ptr<detail::CoilHeatingDXMultiSpeed_Impl> impl)
  : StraightComponent(impl)
{}
/// @endcond

} // model
} // openstudio

