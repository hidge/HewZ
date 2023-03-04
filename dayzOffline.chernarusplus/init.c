void main()
{
	//INIT ECONOMY--------------------------------------
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

}

class CustomMission: MissionServer
{
	void SetRandomHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			float rndHlt = Math.RandomFloat( 1.0, 1.0 );
			itemEnt.SetHealth01( "", "", rndHlt );
		}
	}

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer( identity, characterName, pos, 0, "NONE" );
		Class.CastTo( m_player, playerEnt );

		GetGame().SelectPlayer( identity, m_player );

		return m_player;
	}

	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		EntityAI itemClothing;
		EntityAI itemEnt;
		ItemBase itemBs;
		float rand;

		itemClothing = player.FindAttachmentBySlotName( "Body" );
		if ( itemClothing )
		{
			SetRandomHealth( itemClothing );
			
			itemEnt = player.GetInventory().CreateInInventory( "BandageDressing" );
			itemEnt = player.GetInventory().CreateInInventory( "Matchbox" );
			itemEnt = player.GetInventory().CreateInInventory( "HuntingKnife" );
			SetRandomHealth( itemEnt );
			
			rand = Math.RandomFloatInclusive( 0.0, 1.0 );
			if ( rand < 0.35 )
				itemEnt = player.GetInventory().CreateInInventory( "SpaghettiCan_Opened" );
			else if ( rand > 0.65 )
				itemEnt = player.GetInventory().CreateInInventory( "BakedBeansCan_Opened" );
			else
				itemEnt = player.GetInventory().CreateInInventory( "PeachesCan_Opened" );

			SetRandomHealth( itemEnt );
		
					rand = Math.RandomFloatInclusive( 0.0, 1.0 );
			if ( rand < 0.35 )
				itemEnt = player.GetInventory().CreateInInventory( "SodaCan_Pipsi" );
			else if ( rand > 0.65 )
				itemEnt = player.GetInventory().CreateInInventory( "SodaCan_Spite" );
			else
				itemEnt = player.GetInventory().CreateInInventory( "SodaCan_Kvass" );
			
		}
		
		itemClothing = player.FindAttachmentBySlotName( "Legs" );
		if ( itemClothing )
			SetRandomHealth( itemClothing );
		
		itemClothing = player.FindAttachmentBySlotName( "Feet" );
		if ( itemClothing )
			SetRandomHealth( itemClothing );
	}
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}