﻿/*
 * (c) Copyright Ascensio System SIA 2010-2014
 *
 * This program is a free software product. You can redistribute it and/or 
 * modify it under the terms of the GNU Affero General Public License (AGPL) 
 * version 3 as published by the Free Software Foundation. In accordance with 
 * Section 7(a) of the GNU AGPL its Section 15 shall be amended to the effect 
 * that Ascensio System SIA expressly excludes the warranty of non-infringement
 * of any third-party rights.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without even the implied 
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR  PURPOSE. For 
 * details, see the GNU AGPL at: http://www.gnu.org/licenses/agpl-3.0.html
 *
 * You can contact Ascensio System SIA at Lubanas st. 125a-25, Riga, Latvia,
 * EU, LV-1021.
 *
 * The  interactive user interfaces in modified source and object code versions
 * of the Program must display Appropriate Legal Notices, as required under 
 * Section 5 of the GNU AGPL version 3.
 *
 * Pursuant to Section 7(b) of the License you must retain the original Product
 * logo when distributing the program. Pursuant to Section 7(e) we decline to
 * grant you any rights under trademark law for use of our trademarks.
 *
 * All the Product's GUI elements, including illustrations and icon sets, as
 * well as technical writing content are licensed under the terms of the
 * Creative Commons Attribution-ShareAlike 4.0 International. See the License
 * terms at http://creativecommons.org/licenses/by-sa/4.0/legalcode
 *
 */
 #pragma once
#ifndef DOCX_FOLDER_INCLUDE_H_
#define DOCX_FOLDER_INCLUDE_H_

#include "IFileContainer.h"
#include "RId.h"

namespace Docx
{
	class Folder : public OOX::IFileContainer
	{
	public:
		Folder();
		Folder(const OOX::CPath& path);

	public:
		void read(const OOX::CPath& path);
		void write(const OOX::CPath& path) const;
		void createFromTemplate(const OOX::CPath& path);

	public:
		void Commit(const OOX::CPath& path);
		void Finalize(const OOX::CPath& path);

	public:
		const bool isValid(const OOX::CPath& path) const;

	public:
		void extractPictures(const OOX::CPath& path);
		void extractPictures(const OOX::CPath& source, const OOX::CPath& path);

	public:
		void addImage(const OOX::CPath& imagePath, const long width, const long height);
		void addImageInBegin(const OOX::CPath& imagePath, const long width, const long height);
		void addSpaceToLast(const int count);
		void addPageBreak();
		void addText(const std::wstring& text);
		void addText(const std::string& text);
		void addTextToLast(const std::wstring& text);
		void addTextToLast(const std::string& text);
		void addHyperlink(const std::wstring& nameHref, const std::wstring& text);
		void addHyperlink(const std::string& nameHref, const std::string& text);
		void addHyperlinkToLast(const std::wstring& nameHref, const std::wstring& text);
		void addHyperlinkToLast(const std::string& nameHref, const std::string& text);
	};
} 

#endif //Docx_FOLDER_INCLUDE_H_