#pragma once

#include <puu/tree.hpp>

#include "../resource_loader.hpp"

#include "../render/texture_2d.hpp"

#include "../util/util.hpp"

namespace morda{


/**
 * @brief Texture resource.
 * 
 * %resource description:
 * 
 * @param file - name of the image file, can be raster image.
 * 
 * Example:
 * @code
 * tex_sample{
 *     file{texture_sample.png}
 * }
 * @endcode
 */
class ResTexture : public morda::resource{
	friend class morda::resource_loader;

	std::shared_ptr<texture_2d> tex_v;
public:
	/**
	 * @brief Create texture.
	 * @param c - context.
	 * @param texture - texture object to initialize this resource with.
	 */
	ResTexture(std::shared_ptr<morda::context> c, decltype(tex_v) texture) :
			resource(std::move(c)),
			tex_v(std::move(texture))
	{
		ASSERT(this->tex_v)
	}

	~ResTexture()noexcept{}

	/**
	 * @brief Get texture object held by this resource.
	 * @return Texture object.
	 */
	const texture_2d& tex()const noexcept{
		return *this->tex_v;
	}

private:
	static std::shared_ptr<ResTexture> load(morda::context& ctx, const puu::forest& desc, const papki::file& fi);
};



}
