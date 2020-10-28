/**
 * Copyright 2011 - 2020 José Expósito <jose.exposito89@gmail.com>
 *
 * This file is part of Touchégg.
 *
 * Touchégg is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License  as  published by  the  Free Software
 * Foundation,  either version 3 of the License,  or (at your option)  any later
 * version.
 *
 * Touchégg is distributed in the hope that it will be useful,  but  WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE.  See the  GNU General Public License  for more details.
 *
 * You should have received a copy of the  GNU General Public License along with
 * Touchégg. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef CONFIG_XML_CONFIG_LOADER_H_
#define CONFIG_XML_CONFIG_LOADER_H_

#include <string>

#include "actions/action-type.h"
#include "gesture/gesture-direction.h"
#include "gesture/gesture-type.h"
#include "utils/filesystem.h"
class Config;
namespace pugi {
class xml_node;
}

/**
 * Default config loader. It reads the configuration from
 * "~/.config/touchegg/touchegg.conf" and stores it in `Config`.
 * @see Config
 */
class XmlConfigLoader {
 public:
  /**
   * Default contructor, it takes a pointer to the `Config` object where the
   * configuration will be stored.
   * @param config Pointer to the `Config` object.
   */
  explicit XmlConfigLoader(Config *config);

  /**
   * Store the configuration from the XML configuration file in the `Config`
   * object passed in the constructor.
   */
  void load();

 private:
  /**
   * Pointer to the `Config` object injected in the constructor.
   */
  Config *config;

  /**
   * Parse the XML configuration file placed in path.
   * @param configPath Path to the configuration file.
   */
  void parseXml(const std::filesystem::path &configPath);

  /**
   * Parse the global settings.
   * @param rootNode XML root node, usually named "touchégg".
   */
  void parseGlobalSettings(const pugi::xml_node &rootNode);

  /**
   * Parse the "application" nodes in the XML.
   * @param rootNode XML root node, usually named "touchégg".
   */
  void parseApplicationXmlNodes(const pugi::xml_node &rootNode);

  /**
   * Watch the configuration file and parse it on change.
   * @param configPath Path to the configuration file.
   */
  void watchFile(const std::filesystem::path &configPath);

  /**
   * Check that the required configuration files are in place.
   */
  static void copyConfingIfNotPresent();
};

#endif  // CONFIG_XML_CONFIG_LOADER_H_
