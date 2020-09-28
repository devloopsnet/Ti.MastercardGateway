/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2019 by Axway, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 *
 * Warning: This file is GENERATED, and should not be modified
 */
package net.devloops.mastercard.gateway;

import org.appcelerator.kroll.common.KrollSourceCodeProvider;
import org.appcelerator.kroll.util.KrollAssetHelper;

public class CommonJsSourceProvider implements KrollSourceCodeProvider
{
	public String getSourceCode()
	{
		return getSourceCode("net.devloops.mastercard.gateway");
	}

	public String getSourceCode(String module)
	{
		if (module.equals("${moduleid}/net.devloops.mastercard.gateway")) {
			module = "net.devloops.mastercard.gateway";
		}

		return KrollAssetHelper.readAsset("Resources/net.devloops.mastercard.gateway/" + module + ".js");
	}
}
