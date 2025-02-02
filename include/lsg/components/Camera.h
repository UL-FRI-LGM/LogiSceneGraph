/**
 * Project LogiSceneGraph source code
 * Copyright (C) 2019 Lana Besevic
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LSG_COMPONENTS_CAMERA_H
#define LSG_COMPONENTS_CAMERA_H

#include <glm/glm.hpp>

#include "lsg/core/Component.h"

namespace lsg {

class Camera : public Component {
public:
	using Component::Component;

	virtual const glm::mat4x4& projectionMatrix() = 0;
};

}

#endif // LSG_COMPONENTS_CAMERA_H