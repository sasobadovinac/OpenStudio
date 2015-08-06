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

#ifndef MODEL_COILHEATINGWATERTOAIRHEATPUMPVARIABLESPEEDEQUATIONFITSPEEDDATA_HPP
#define MODEL_COILHEATINGWATERTOAIRHEATPUMPVARIABLESPEEDEQUATIONFITSPEEDDATA_HPP

#include "ModelAPI.hpp"
#include "ParentObject.hpp"

namespace openstudio {

namespace model {

class CurveBiquadratic;
class CurveQuadratic;

namespace detail {

  class CoilHeatingWaterToAirHeatPumpVariableSpeedEquationFitSpeedData_Impl;

} // detail

/** CoilHeatingWaterToAirHeatPumpVariableSpeedEquationFitSpeedData is a ParentObject that wraps the OpenStudio IDD object 'OS:Coil:Heating:WaterToAirHeatPump:VariableSpeedEquationFit:SpeedData'. */
class MODEL_API CoilHeatingWaterToAirHeatPumpVariableSpeedEquationFitSpeedData : public ParentObject {
 public:
  /** @name Constructors and Destructors */
  //@{

  explicit CoilHeatingWaterToAirHeatPumpVariableSpeedEquationFitSpeedData(const Model& model);

  virtual ~CoilHeatingWaterToAirHeatPumpVariableSpeedEquationFitSpeedData() {}

  //@}

  static IddObjectType iddObjectType();

  /** @name Getters */
  //@{

  double referenceUnitGrossRatedHeatingCapacity() const;

  double referenceUnitGrossRatedHeatingCOP() const;

  double referenceUnitRatedAirFlow() const;

  double referenceUnitRatedWaterFlowRate() const;

  CurveBiquadratic heatingCapacityFunctionofTemperatureCurve() const;

  CurveQuadratic totalHeatingCapacityFunctionofAirFlowFractionCurve() const;

  CurveQuadratic heatingCapacityFunctionofWaterFlowFractionCurve() const;

  CurveBiquadratic energyInputRatioFunctionofTemperatureCurve() const;

  CurveQuadratic energyInputRatioFunctionofAirFlowFractionCurve() const;

  CurveQuadratic energyInputRatioFunctionofWaterFlowFractionCurve() const;

  double referenceUnitWasteHeatFractionofInputPowerAtRatedConditions() const;

  CurveBiquadratic wasteHeatFunctionofTemperatureCurve() const;

  //@}
  /** @name Setters */
  //@{

  bool setReferenceUnitGrossRatedHeatingCapacity(double referenceUnitGrossRatedHeatingCapacity);

  bool setReferenceUnitGrossRatedHeatingCOP(double referenceUnitGrossRatedHeatingCOP);

  bool setReferenceUnitRatedAirFlow(double referenceUnitRatedAirFlow);

  bool setReferenceUnitRatedWaterFlowRate(double referenceUnitRatedWaterFlowRate);

  bool setHeatingCapacityFunctionofTemperatureCurve(const CurveBiquadratic& curveBiquadratic);

  bool setTotalHeatingCapacityFunctionofAirFlowFractionCurve(const CurveQuadratic& curveQuadratic);

  bool setHeatingCapacityFunctionofWaterFlowFractionCurve(const CurveQuadratic& curveQuadratic);

  bool setEnergyInputRatioFunctionofTemperatureCurve(const CurveBiquadratic& curveBiquadratic);

  bool setEnergyInputRatioFunctionofAirFlowFractionCurve(const CurveQuadratic& curveQuadratic);

  bool setEnergyInputRatioFunctionofWaterFlowFractionCurve(const CurveQuadratic& curveQuadratic);

  bool setReferenceUnitWasteHeatFractionofInputPowerAtRatedConditions(double referenceUnitWasteHeatFractionofInputPowerAtRatedConditions);

  bool setWasteHeatFunctionofTemperatureCurve(const CurveBiquadratic& curveBiquadratic);

  //@}
  /** @name Other */
  //@{

  //@}
 protected:
  /// @cond
  typedef detail::CoilHeatingWaterToAirHeatPumpVariableSpeedEquationFitSpeedData_Impl ImplType;

  explicit CoilHeatingWaterToAirHeatPumpVariableSpeedEquationFitSpeedData(std::shared_ptr<detail::CoilHeatingWaterToAirHeatPumpVariableSpeedEquationFitSpeedData_Impl> impl);

  friend class detail::CoilHeatingWaterToAirHeatPumpVariableSpeedEquationFitSpeedData_Impl;
  friend class Model;
  friend class IdfObject;
  friend class openstudio::detail::IdfObject_Impl;
  /// @endcond
 private:
  REGISTER_LOGGER("openstudio.model.CoilHeatingWaterToAirHeatPumpVariableSpeedEquationFitSpeedData");
};

/** \relates CoilHeatingWaterToAirHeatPumpVariableSpeedEquationFitSpeedData*/
typedef boost::optional<CoilHeatingWaterToAirHeatPumpVariableSpeedEquationFitSpeedData> OptionalCoilHeatingWaterToAirHeatPumpVariableSpeedEquationFitSpeedData;

/** \relates CoilHeatingWaterToAirHeatPumpVariableSpeedEquationFitSpeedData*/
typedef std::vector<CoilHeatingWaterToAirHeatPumpVariableSpeedEquationFitSpeedData> CoilHeatingWaterToAirHeatPumpVariableSpeedEquationFitSpeedDataVector;

} // model
} // openstudio

#endif // MODEL_COILHEATINGWATERTOAIRHEATPUMPVARIABLESPEEDEQUATIONFITSPEEDDATA_HPP

