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
#ifndef PPTX_LOGIC_DUOTONE_INCLUDE_H_
#define PPTX_LOGIC_DUOTONE_INCLUDE_H_

#include "./../../WrapperWritingElement.h"
#include "./../UniColor.h"

namespace PPTX
{
	namespace Logic
	{
		class Duotone : public WrapperWritingElement
		{
		public:
			PPTX_LOGIC_BASE(Duotone)

			Duotone& operator=(const Duotone& oSrc)
			{
				parentFile		= oSrc.parentFile;
				parentElement	= oSrc.parentElement;

				Colors.Copy(oSrc.Colors);
				return *this;
			}

		public:
			virtual void fromXML(XmlUtils::CXmlNode& node)
			{
				Colors.RemoveAll();
				node.LoadArray(_T("*"), Colors);
				FillParentPointersForChilds();
			}

			virtual CString toXML() const
			{
				XmlUtils::CNodeValue oValue;
				oValue.WriteArray(Colors);

				return XmlUtils::CreateNode(_T("a:duotone"), oValue);
			}

			virtual void toPPTY(NSBinPptxRW::CBinaryFileWriter* pWriter) const
			{
				pWriter->StartRecord(EFFECT_TYPE_DUOTONE);

				ULONG len = (ULONG)Colors.GetCount();
				pWriter->WriteULONG(len);
				
				for (ULONG i = 0; i < len; ++i)
				{
					pWriter->WriteRecord1(0, Colors[i]);
				}

				pWriter->EndRecord();
			}

		public:
			CAtlArray<UniColor> Colors;
		protected:
			virtual void FillParentPointersForChilds()
			{
				size_t count = Colors.GetCount();
				for (size_t i = 0; i < count; ++i)
					Colors[i].SetParentPointer(this);
			}
		};
	} 
} 

#endif // PPTX_LOGIC_DUOTONE_INCLUDE_H_