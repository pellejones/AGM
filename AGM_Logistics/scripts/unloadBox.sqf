// commy 2

_vehicle = AGM_Interaction_Target;

_loadedItems = _vehicle getVariable ["AGM_Logistics_loadedItems", []];

_count = count _loadedItems;

if (_count == 0) exitWith {};

_item = _loadedItems select (_count - 1);
_loadedItems resize (_count - 1);

_vehicle setVariable ["AGM_Logistics_loadedItems", _loadedItems, true];

_itemName = getText (configFile >> "CfgVehicles" >> typeOf _item >> "displayName");
_vehicleName = getText (configFile >> "CfgVehicles" >> typeOf _vehicle >> "displayName");
[format ["unloaded %1 from %2", _itemName, _vehicleName], true] call AGM_Core_fnc_displayText;
