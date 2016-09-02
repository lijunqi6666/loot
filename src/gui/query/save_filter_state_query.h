/*  LOOT

A load order optimisation tool for Oblivion, Skyrim, Fallout 3 and
Fallout: New Vegas.

Copyright (C) 2014-2016    WrinklyNinja

This file is part of LOOT.

LOOT is free software: you can redistribute
it and/or modify it under the terms of the GNU General Public License
as published by the Free Software Foundation, either version 3 of
the License, or (at your option) any later version.

LOOT is distributed in the hope that it will
be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with LOOT.  If not, see
<https://www.gnu.org/licenses/>.
*/

#ifndef LOOT_GUI_QUERY_SAVE_FILTER_STATE_QUERY
#define LOOT_GUI_QUERY_SAVE_FILTER_STATE_QUERY

#include <boost/log/trivial.hpp>

#include "backend/app/loot_state.h"
#include "gui/query/query.h"

namespace loot {
class SaveFilterStateQuery : public Query {
public:
  SaveFilterStateQuery(LootState& state,
                       const std::string& filterId,
                       bool enabled) :
    state_(state), filterId_(filterId), enabled_(enabled) {}

  void execute(CefRefPtr<CefMessageRouterBrowserSide::Callback> callback) {
    BOOST_LOG_TRIVIAL(trace) << "Saving filter states.";
    state_.storeFilterState(filterId_, enabled_);
    callback->Success("");
  }

private:
  LootState& state_;
  std::string filterId_;
  bool enabled_;
};
}

#endif