# Databases

## City Distances and Foods
SQLim - relational
Used for finding foods and distances associated with cities ().
* ex: distances.json


## Travel Plan Records
IndexedDB - non-relational
Used for record keeping (tripRecord) and trip recommendation (tripSelector).
* ex: _tripRecordExample.json


## Persistent State
LocalStorage - relational
Used for fetching and storing state.

Items                  |
-----------------------|--------------------
- "is_admin",          | modify cities/foods
- "is_plan_active",    | jump to active plan
- "is_plan_complete",  | jump to plan record
- "is_plan_drafted"    | jump to saved plan


## Travel Plan Options
JS Object - non-relational
Used for trip templates (tripSelector).
* ex: defaultPlans.json