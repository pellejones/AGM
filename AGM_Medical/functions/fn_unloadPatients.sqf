/*
 * Author: KoffeinFlummi
 *
 * Unloads the wounded units from the vehicle.
 *
 * Arguments:
 * 0: The vehicle
 *
 * Return Value:
 * -
 */

 private ["_unit", "_vehicle"];

_vehicle = _this select 0;

{
  if (_x getVariable "AGM_Unconscious") then {
    [-2, {
      _unit = _this select 0;
      _player = _this select 1;
      if (local _unit) then {
        _unit setPosATL [(getPos _player select 0) + (random 2) - 1, (getPos _player select 1) + (random 2) - 1, 0];
      };
      _unit switchMove "Unconscious";
    }, [_x, player]] call CBA_fnc_globalExecute;
  };
} forEach crew _vehicle;